#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
pair<int, pair<int, int > > p[N];

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; ++i) {
    int ai, ti;
    scanf("%d %d", &ai, &ti);
    p[i] = {ti, {ai, i} };
  }
  sort(p, p+n);
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    int cnt = 0, cur = t;
    for (int i = 0; i < n; ++i) {
      if (cur < p[i].first) break;
      if (p[i].second.first < mid) continue;
      cnt++;
      cur -= p[i].first;
    }
    if (cnt >= mid)
      l = mid;
    else
      r = mid - 1;
  }
  int ans = l;
  printf("%d\n%d\n", ans, ans);
  int cur = t;
  for (int i = 0; i < n && ans > 0; ++i) {
    if (p[i].second.first < l) continue;
    ans--;
    printf("%d%c", p[i].second.second+1, ans ? ' ' : '\n');
  } 
  return 0;
}