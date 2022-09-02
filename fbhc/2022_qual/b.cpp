#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  vector<vector<int>> deg(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') continue;
      if (i > 0 && grid[i-1][j] != '#') {
        ++deg[i][j];
        ++deg[i-1][j];
      }
      if (j > 0 && grid[i][j-1] != '#') {
        ++deg[i][j];
        ++deg[i][j-1];
      }
    }
  }
  queue<pair<int, int>> que;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (deg[i][j] == 1) {
        que.emplace(i, j);
      }
    }
  }
  vector<int> dr = {-1, 0, 1, 0};
  vector<int> dc = {0, -1, 0, 1};
  while (!que.empty()) {
    int r, c;
    tie(r, c) = que.front();
    que.pop();
    int cnt = deg[r][c];
    deg[r][c] = 0;
    for (int i = 0; i < 4; ++i) {
      int x = r + dr[i];
      int y = c + dc[i];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (grid[x][y] == '#' || deg[x][y] <= 0) continue;
      --deg[x][y];
      --cnt;
      if (deg[x][y] == 1)
        que.emplace(x, y);
    }
    assert(cnt == 0);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '^' && deg[i][j] < 2) {
        puts("Impossible");
        return;
      }
      if (deg[i][j] >= 2) {
        assert(grid[i][j] != '#');
        grid[i][j] = '^';
      }
    }
  }
  puts("Possible");
  for (int i = 0; i < n; ++i)
    cout << grid[i] << '\n';
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
