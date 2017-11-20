#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<int> a[N];
long long b[N];

vector<pair<int, long long> > process(vector<pair<int, long long> > prev, vector<int> & cur, int x) {
  vector<pair<int, int> > sorted(cur.size());
  for (int i = 0; i < cur.size(); i++)
    sorted[i] = {cur[i], i};
  sort(sorted.begin(), sorted.end());
  sort(prev.begin(), prev.end());
  int last = prev[0].first;
  long long now = 0;
  for (int i = 0, j = 0; i < sorted.size(); i++) {
    pair<int, int> s = sorted[i];
    while (j < prev.size() && prev[j].first <= s.first) {
      pair<int, long long> it = prev[j];
      now += 1LL * (it.first - last) * x;
      now = max(now, it.second);
      last = it.first;
      j++;
    }
    if (last < s.first) {
      now += 1LL * (s.first - last) * x;
      last = s.first;
    }
    b[s.second] = now;
  }
  now = 0;
  last = prev.back().first;
  for (int i = (int)sorted.size() - 1, j = (int)prev.size()-1; i >= 0; i--) {
    pair<int, int> s = sorted[i];
    while (j >= 0 && prev[j].first >= s.first) {
      pair<int, long long> it = prev[j];
      now += 1LL * (last - it.first) * x;
      now = max(now, it.second);
      last = it.first;
      j--;
    }
    if (last > s.first) {
      now += 1LL * (last - s.first) * x;
      last = s.first;
    }
    b[s.second] = max(b[s.second], now);
  }
  vector<pair<int, long long > > res(cur.size());
  for (int i = 0; i < cur.size(); i++)
    res[i] = {cur[(i + (int)cur.size() - 1) % cur.size()], b[i]};
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      a[i].clear();
      int m;
      scanf("%d", &m);
      while (m--) {
        int x;
        scanf("%d", &x);
        a[i].push_back(x);
      }
    }
    vector<pair<int, long long > > res(a[0].size());
    for (int i = 0; i < a[0].size(); i++)
      res[i] = {a[0][i], 0};
    for (int i = 1; i < n; i++) {
      res = process(res, a[i], i);
    }
    long long ans = 0;
    for (auto it : res)
      ans = max(ans, it.second);
    printf("%lld\n", ans);
  }
  return 0;
}