#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
      scanf("%d", &a[i][j]);
  }
  vector<int> best(m);
  iota(best.begin(), best.end(), 0);
  for (int i = 0; i + 1 < n; ++i) {
    vector<pair<int, int>> dif;
    for (int j = 0; j < m; ++j) {
      dif.emplace_back(a[j][i] - a[j][n-1], j);
    }
    sort(dif.begin(), dif.end());
    reverse(dif.begin(), dif.end());
    int sum = 0, cur = 0;
    while (cur < m && sum + dif[cur].first >= 0) {
      sum += dif[cur].first;
      ++cur;
    }
    if (m - cur < (int)best.size()) {
      best.clear();
      for (int j = cur; j < m; ++j) {
        best.emplace_back(dif[j].second);
      }
    }
  }
  printf("%d\n", (int)best.size());
  sort(best.begin(), best.end());
  for (int i = 0; i < (int)best.size(); ++i) {
    printf("%d%c", best[i]+1, i+1 == (int)best.size() ? '\n' : ' ');
  }
  return 0;
}
