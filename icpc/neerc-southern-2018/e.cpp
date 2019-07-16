#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int cnt[N];
long long sum[N];
int n;

void upd_cnt(int x, int v) {
  for (; x <= n; x += x&-x)
    cnt[x] += v;
}
int get_cnt(int x) {
  int ret = 0;
  for (; x; x-=x&-x)
    ret += cnt[x];
  return ret;
}
int find_cnt(int v) {
  int x = 0;
  for (int i = 20; i >= 0; --i) {
    int now = x + (1 << i);
    if (now > n) continue;
    if (cnt[now] > v) continue;
    v -= cnt[now];
    x = now;
  }
  return x;
}


void upd_sum(int x, long long v) {
  for (; x <= n; x += x&-x)
    sum[x] += v;
}
long long get_sum(int x) {
  long long ret = 0;
  for (; x; x-=x&-x)
    ret += sum[x];
  return ret;
}
int find_sum(long long v) {
  int x = 0;
  int ret = 0;
  for (int i = 20; i >= 0; --i) {
    int now = x + (1 << i);
    if (now > n) continue;
    if (sum[now] > v) continue;
    v -= sum[now];
    x = now;
    ret += cnt[now];
  }
  return ret;
}

int p[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    long long k;
    scanf("%d %d %lld", &n, &m, &k);
    fill(sum, sum + n+1, 0);
    fill(cnt, cnt + n+1, 0);
    vector<pair<int, int> > vp;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", p+i);
      vp.emplace_back(p[i], i);
    }
    int ans = 0, d = 1;
    sort(vp.begin(), vp.end());
    for (int j = 0; j < vp.size();) {
      int now = vp[j].first;
      while (j < vp.size() && vp[j].first == now) {
        upd_sum(vp[j].second, now);
        upd_cnt(vp[j].second, 1);
        ++j;
      }
      int x = find_sum(k/2);
      int full = x / m;
      x = full * m;
      int pos = find_cnt(x);
      long long sisa = k - get_sum(pos);
      int cur = min(find_sum(sisa), x+m);
      if (ans < cur) {
        ans = cur;
        d = now;
      }
    }
    printf("%d %d\n", ans, d);
  }
  return 0;
}