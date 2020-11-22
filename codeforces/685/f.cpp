#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int ans = 0;
  vector<int> val(n+m, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      val[i+j] ^= a[i][j];
    }
  }
  ans = *max_element(val.begin(), val.end());
  puts(ans ? "Ashish" : "Jeel");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
