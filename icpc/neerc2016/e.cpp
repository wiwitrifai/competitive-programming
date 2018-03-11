// by wiwit
#include <bits/stdc++.h>

using namespace std;
const string filename = "expect";

const int N = 1e5 + 6;

int b[N];
long long ans[N];
int t[N], k[N];
long long add[3 * N];
vector<int> que[3 * N];

int main() {
#ifndef LOCAL
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    char c;
    scanf(" %c %d %d", &c, t+i, k+i);
    if (c == '-')
      k[i] *= -1;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d", b+i);
  }
  long long sum = 0;
  long long now = 0;
  vector<pair<long long, int > > event;
  for (int i = 0; i < n; ++i) {
    if (k[i] < 0) {
      long long butuh = -k[i];
      long long hapus = min(butuh, max(now, 0LL));
      butuh -= hapus;
      now -= hapus;
      if (butuh > 0) {
        event.emplace_back(-now, +t[i]);
        event.emplace_back(-now + butuh, -t[i]);
        now -= butuh;
        sum -= butuh * t[i];
      }
    }
    else {
      long long tambah = k[i];
      long long match = min(tambah, max(-now, 0LL));
      tambah -= match;
      if (match > 0) {
        now += match;
        event.emplace_back(max(0LL, -now), -t[i]);
        event.emplace_back(max(0LL, -now) + match, +t[i]);
        sum += match * t[i];
      }
      now += tambah;
    }
  }
  vector<long long> vx;
  for (auto it : event) {
    vx.push_back(it.first);
  }
  for (int i = 0; i < q; ++i) {
    vx.push_back(b[i]);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  for (auto it : event) {
    int pos = lower_bound(vx.begin(), vx.end(), it.first) - vx.begin();
    add[pos] += it.second;
  }
  for (int i = 0; i < q; ++i) {
    int pos = lower_bound(vx.begin(), vx.end(), b[i]) - vx.begin();
    que[pos].push_back(i);
  }
  int last = 0;
  long long vadd = 0;
  for (int i = 0; i < vx.size(); ++i) {
    sum += vadd * (vx[i] - last);
    last = vx[i];
    vadd += add[i];
    for (int id : que[i]) {
      if (vx[i] < -now)
        ans[id] = -1;
      else
        ans[id] = sum;
    }
  }
  for (int i = 0; i < q; ++i) {
    if (ans[i] < 0) {
      puts("INFINITY");
      continue;
    }
    printf("%lld\n", ans[i]);
  }
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout); 
#endif
  return 0;
}