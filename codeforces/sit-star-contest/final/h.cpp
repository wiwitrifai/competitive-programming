#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  vector<pair<int, int>> x(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i].first);
    x[i].second = i;
  }
  sort(x.begin(), x.end());
  int k = 1;
  for (int i = 0, r = 0; i < n; ++i) {
    while (r < n && x[r].first - x[i].first < d) ++r;
    k = max(k, r-i);
  }
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[x[i].second] = (i % k) + 1;
  }
  printf("%d\n", k);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
  }
  return 0;
}
