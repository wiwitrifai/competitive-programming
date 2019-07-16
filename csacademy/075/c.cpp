#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, x, y;
int d[N], v[N];
vector<tuple<int, int, int, int> > f, s;

bool cmp(tuple<int, int, int, int> le, tuple<int, int, int, int> ri) {
  int dl, vl, il, cl, dr, vr, ir, cr;
  tie(dl, vl, il, cl) = le;
  tie(dr, vr, ir, cr) = ri;
  long long val = 1LL * dl * vr - 1LL * dr * vl;
  if (val == 0) {
    return il < ir;
  }
  return val < 0;
}

int ans[N];

int main() {
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", d+i, v+i);
    f.emplace_back(d[i], v[i], i, 1);
    f.emplace_back(d[i], v[i] + x, i, 0);
    s.emplace_back(d[i], v[i] - y, i, 1);
    s.emplace_back(d[i], v[i], i, 0);
    ans[i] = n;
  }
  sort(f.begin(), f.end(), cmp);
  sort(s.begin(), s.end(), cmp);
  for (int i = 0, now = 0; i < f.size(); ++i) {
    int dl, vl, id, cost;
    tie(dl, vl, id, cost) = f[i];
    ans[id] = min(ans[id], now+1);
    now += cost;
  }
  for (int i = 0, now = 0; i < s.size(); ++i) {
    int dl, vl, id, cost;
    tie(dl, vl, id, cost) = s[i];
    ans[id] = min(ans[id], now+1);
    now += cost;
  }
  for (int i = 0; i < n; ++i)
    printf("%d\n", ans[i]);
  return 0;
}