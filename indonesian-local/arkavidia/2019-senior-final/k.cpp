#include <bits/stdc++.h>

using namespace std;

const int N = 22, S = 6, mod = 1e9 + 7;
#define XY_FRONT 0
#define XY_BACK 1
#define XZ_FRONT 2
#define XZ_BACK 3
#define YZ_FRONT 4
#define YZ_BACK 5

int n;
int grid[S * N * N];
bool vis[S * N * N];
int enc(int s, int x, int y) {
  return (s * n + x) * n + y;
}
vector<int> cycle[3 * N];
int tmp_cyc[N * 4];
int temp[N][N];

void rotate_side_ccw(int s) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      temp[i][j] = grid[enc(s, j, n-1-i)];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      grid[enc(s, i, j)] = temp[i][j];
    }
  }
}

void rotate_side_cw(int s) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      temp[j][n-1-i] = grid[enc(s, i, j)];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      grid[enc(s, i, j)] = temp[i][j];
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < S * n * n; ++i) {
      grid[i] = i;
    }
    for (int i = 0; i < n * 3; ++i)
      cycle[i].clear();
    // Cycle X
    for (int p = 0; p < n; ++p) {
      int idx = p;
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(XY_FRONT, p, i));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(XZ_FRONT, p, i));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(XY_BACK, p, n-1-i));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(XZ_BACK, p, n-1-i));
    }
    // Cycle Y
    for (int p = 0; p < n; ++p) {
      int idx = n+p;
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(XY_FRONT, n-1-i, p));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(YZ_FRONT, p, i));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(XY_BACK, i, p));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(YZ_BACK, p, n-1-i));
    }
    // Cycle Z
    for (int p = 0; p < n; ++p) {
      int idx = 2*n+p;
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(XZ_FRONT, n-1-i, p));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(YZ_FRONT, n-1-i, p));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(XZ_BACK, i, p));
      for (int i = 0; i < n; ++i)
        cycle[idx].push_back(enc(YZ_BACK, i, p));
    }
    while (m--) {
      char cmd[5];
      int p;
      scanf("%s %d", cmd, &p);
      int d = n;
      int idx;
      if ('x' <= cmd[0] && cmd[0] <= 'z') {
        d = 3 * n;
        idx = (cmd[0] - 'x') * n + p - 1;
      }
      else
        idx = (cmd[0] - 'X') * n + p - 1;
      for (int i = 0; i < 4 * n; ++i)
        tmp_cyc[i] = grid[cycle[idx][i]];
      for (int i = 0; i < 4 * n; ++i) {
        int j = i+d;
        if (j >= 4 * n)
          j -= 4 * n;
        grid[cycle[idx][j]] = tmp_cyc[i];
      }
      if (p == 1) {
        if (cmd[0] == 'x') rotate_side_cw(YZ_FRONT);
        if (cmd[0] == 'X') rotate_side_ccw(YZ_FRONT);

        if (cmd[0] == 'y') rotate_side_ccw(XZ_BACK);
        if (cmd[0] == 'Y') rotate_side_cw(XZ_BACK);

        if (cmd[0] == 'z') rotate_side_cw(XY_FRONT);
        if (cmd[0] == 'Z') rotate_side_ccw(XY_FRONT);
      }
      else if (p == n) {
        if (cmd[0] == 'x') rotate_side_cw(YZ_BACK);
        if (cmd[0] == 'X') rotate_side_ccw(YZ_BACK);

        if (cmd[0] == 'y') rotate_side_ccw(XZ_FRONT);
        if (cmd[0] == 'Y') rotate_side_cw(XZ_FRONT);

        if (cmd[0] == 'z') rotate_side_cw(XY_BACK);
        if (cmd[0] == 'Z') rotate_side_ccw(XY_BACK);
      }
    }
    memset(vis, 0, sizeof vis);
    vector<int> periods;
    for (int i = 0; i < S * n * n; ++i) {
      if (vis[i]) continue;
      int now = i;
      vector<int> color;
      int nn = n * n;
      while (!vis[now]) {
        color.push_back(now / nn);
        vis[now] = 1;
        now = grid[now];
      }
      int len = 1;
      while (len < color.size()) {
        bool same = 1;
        for (int i = 0; i < color.size(); ++i) {
          int j = i + len;
          if (j >= color.size())
            j -= color.size();
          if (color[i] != color[j]) {
            same = 0;
            break;
          }
        }
        if (same) break;
        ++len;
      }
      periods.push_back(len);
    }
    long long ans = 1;
    map<int, int> factors;
    for (int len : periods) {
      for (int i = 2; i * i <= len; ++i) {
        if (len % i) continue;
        int cnt = 0;
        while ((len % i) == 0) {
          ++cnt;
          len /= i;
        }
        factors[i] = max(factors[i], cnt);
      }
      if (len > 1)
        factors[len] = max(factors[len], 1);
    }
    for (auto it : factors) {
      for (int i = 0; i < it.second; ++i)
        ans = (ans * it.first) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}