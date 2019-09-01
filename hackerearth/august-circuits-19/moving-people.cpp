#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<string> grid(n);
  for (int i = 0; i < n; ++i)
    cin >> grid[i];
  vector<vector<int>> presum(n+1, vector<int>(m+1, 0));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i + 1 <= n)
        presum[i+1][j] += presum[i][j];
      if (j + 1 <= m)
        presum[i][j+1] += presum[i][j];
      if (i + 1 <= n && j + 1 <= m) {
        presum[i+1][j+1] += grid[i][j] == '1'; 
        presum[i+1][j+1] -= presum[i][j];
      }
    }
  }
  int lef = 0, rig = m, top = 0, bot = n;
  int posx = 0, posy = 0;
  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      posx -= x;
      posy -= y;
      posx = max(min(posx, m), -m);
      posy = max(min(posy, n), -n);
      lef = min(max(0 - posx, lef), rig);
      rig = max(min(m - posx, rig), lef);
      top = min(max(0 - posy, top), bot);
      bot = max(min(n - posy, bot), top);
    }
    else {
      printf("%d\n", presum[bot][rig] - presum[bot][lef] - presum[top][rig] + presum[top][lef]);
    }
  }
  return 0;
}
