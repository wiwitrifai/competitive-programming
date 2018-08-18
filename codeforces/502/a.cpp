#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > g;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < 4; ++j) {
      int v;
      scanf("%d", &v);
      sum += v;
    }
    g.emplace_back(-sum, i);
  }
  sort(g.begin(), g.end());
  int ans = -1;
  for (int i = 0; i < n; ++i)
    if (g[i].second == 0)
      ans = i+1;
  printf("%d\n", ans );
  return 0;
}