#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> grid(n, vector<int>(m, 0));
  vector<vector<bool>> done(n, vector<bool>(m, false));
  vector<vector<int>> down(n, vector<int>(m, -1)), up(n, vector<int>(m, -1)), lef(n, vector<int>(m, -1)), rig(n, vector<int>(m, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &grid[i][j]);
      if (i+1 < n) {
        down[i][j] = i+1;
        up[i+1][j] = i;
      }
      if (j+1 < m) {
        rig[i][j] = j+1;
        lef[i][j+1] = j;
      }
    }
  }

  auto rem = [&](int r, int c) {
    if (grid[r][c] == 0) return;
    grid[r][c] = 0;
    int u = up[r][c], d = down[r][c];
    if (d != -1)
      up[d][c] = u;
    if (u != -1)
      down[u][c] = d;
    int le = lef[r][c], ri = rig[r][c];
    if (le != -1)
      rig[r][le] = ri;
    if (ri != -1)
      lef[r][ri] = le;
  };
  long long ans = 0;
  queue<pair<int, int>> que, nxt;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      que.emplace(i, j);
    }
  }
  for (int x = 1; ; ++x) {
    queue<pair<int, int>> tmp;
    while (!que.empty()) {
      int r, c;
      r = que.front().first, c = que.front().second;
      que.pop();
      if (grid[r][c] == 0 || done[r][c])
        continue;
      int cnt = 0, sum = 0;
      if (up[r][c] != -1)
        ++cnt, sum += grid[up[r][c]][c];
      if (down[r][c] != -1)
        ++cnt, sum += grid[down[r][c]][c];
      if (lef[r][c] != -1)
        ++cnt, sum += grid[r][lef[r][c]];
      if (rig[r][c] != -1)
        ++cnt, sum += grid[r][rig[r][c]];
      if (cnt * grid[r][c] < sum) {
        tmp.emplace(r, c);
        done[r][c] = true;
        if (up[r][c] != -1) {
          nxt.emplace(up[r][c], c);
        }
        if (down[r][c] != -1) {
          nxt.emplace(down[r][c], c);
        }
        if (lef[r][c] != -1) {
          nxt.emplace(r, lef[r][c]);
        }
        if (rig[r][c] != -1) {
          nxt.emplace(r, rig[r][c]);
        }
      }
    }
    if (tmp.empty()) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == 0) continue;
          ans += 1LL * x * grid[i][j];
        }
      }
      break;
    }
    while (!tmp.empty()) {
      int r, c;
      r = tmp.front().first, c = tmp.front().second;
      tmp.pop();
      ans += 1LL * x * grid[r][c];
      rem(r, c);
    }
    que.swap(nxt);
  }
  printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
