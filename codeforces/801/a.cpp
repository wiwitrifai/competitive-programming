#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  int r = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[r][c] < a[i][j]) {
        r = i;
        c = j;
      }
    }
  }
  int ans = max(r+1, n-r) * max(c+1, m-c);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
