#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> vs(n);
  for (int i = 0; i < n; ++i)
    cin >> vs[i];
  for (int i = n-1; i >= 0; --i) {
    for (int j = m-1; j >= 0; --j) {
      bool ok = false;
      static vector<int> dx = {-1, -1, 0, 0};
      static vector<int> dy = {-1, 0, -1, 0};
      for (int k = 0; k < 4; ++k) {
        int r = i + dx[k], c = j + dy[k];
        if (r < 0 || c < 0) continue;
        ok |= vs[r][c] == '#';
      }
      if (ok)
        vs[i][j] = '#';
    }
  }
  for (int i = 0; i < n; ++i)
    cout << vs[i] << '\n';
  return 0;
}
