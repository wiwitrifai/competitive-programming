#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;

pair<int, int> find() {
  int n = grid.size();
  pair<int, int> ret = {0, 0};
  int best = grid[0][0];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (best > grid[i][j]) {
        best = grid[i][j];
        ret = {i, j};
      }
    }
  }
  return ret;
}

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

pair<int, int> move(int r, int c, int d) {
  pair<int, int> ret = {r, c};
  int best = grid[r][c];
  int n = grid.size();
  for (int i = 0; i < 8; i += d) {
    int rr = r, cc = c;
    while (0 <= min(rr, cc) && max(rr, cc) < n) {
      if (best > grid[rr][cc]) {
        best = grid[rr][cc];
        ret = {rr, cc};
      }
      rr += dy[i];
      cc += dx[i];
    }
  }
  return ret;
}

const int inf = 1e9 + 7;

int calc(int d) {
  int ans = -1;
  while (1) {
    pair<int, int> cur = find();
    if (grid[cur.first][cur.second] >= inf)
      return ans;
    ++ans;
    while (grid[cur.first][cur.second] < inf) {
      grid[cur.first][cur.second] = inf;
      cur = move(cur.first, cur.second, d);
    }
  }
}

int main() {
  int n = 3;
  vector<int> p(n * n);
  iota(p.begin(), p.end(), 0);
  grid.assign(n, vector<int>(n, inf));
  do {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        grid[i][j] = p[i * n + j];
      }
    }
    vector<vector<int>> tmp = grid;
    int rock = calc(2);
    grid = tmp;
    int queen = calc(1);
    grid = tmp;
    if (rock < queen) {
      if (grid[2][2] == 0)
        break;
    }
  } while (next_permutation(p.begin(), p.end()));
  scanf("%d", &n);
  if (n < 3) {
    puts("-1");
    return 0;
  }
  vector<vector<int>> ans(n, vector<int>(n, -1));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ans[n - 3 + i][n-3 + j] = grid[i][j] + n * n - 8;
    }
  }
  bool lef = true;
  if (n & 1) {
    lef = false;
  }
  int now = 1;
  for (int i = 0; i < n; ++i) {
    if (lef) {
      for (int j = n-1; j >= 0; --j) {
        if (ans[i][j] != -1) continue;
        ans[i][j] = now++;
      }
    }
    else {
      for (int j = 0; j < n; ++j) {
        if (ans[i][j] != -1) continue;
        ans[i][j] = now++;
      }
    }
    lef = !lef;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d%c", ans[i][j], j+1 == n ? '\n' : ' ');
    }
  }
  // grid = ans;
  // int rook = calc(2);
  // grid = ans;
  // int queen = calc(1);
  // assert(rook < queen);
  return 0;
}
