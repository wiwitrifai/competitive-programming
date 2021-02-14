#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const long long inf = 1e18;

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {}
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  void reset() {
    fill(p.begin(), p.end(), -1);
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (u < v)
      swap(u, v);
    p[u] = v;
    return true;
  }
};

int a[3][N];
int b[2][N];
long long cost[9];

long long dp[2][28][9];
int employee[N];

inline void upd(long long & var, long long x) {
  if (var > x)
    var = x;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n-1; ++j) {
      scanf("%d", a[i]+j);
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", b[i]+j);
    }
  }
  int last = -1;
  for (int i = 0; i < m; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    --r, --c;
    employee[c] |= 1 << r;
    last = max(last, c);
  }
  Dsu dsu(6);
  int cur = 0, bef = 1;
  for (int j = 0; j < 27; ++j)
    for (int k = 0; k < 8; ++k)
      dp[cur][j][k] = inf;
  dp[cur][0 * 1 + 1 * 3 + 2 * 9][employee[0]] = 0;
  int col[3];
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      for (int mask = 0; mask < 8; ++mask) {
        cost[mask] = 0;
        for (int z = 2; z >= 0; --z) {
          if (mask & (1 << z)) {
            cost[mask] += a[z][i-1];
          }
        }
      }
      swap(bef, cur);
      for (int j = 0; j < 27; ++j)
        for (int k = 0; k < 8; ++k)
          dp[cur][j][k] = inf;
      for (int j = 0; j < 27; ++j) {
        int x = j;
        for (int z = 0; z < 3; ++z) {
          col[z] = x % 3;
          x /= 3;
        }
        for (int k = 0; k < 8; ++k) {
          long long now = dp[bef][j][k];
          if (now >= inf) continue;
          for (int mask = 0; mask < 8; ++mask) {
            dsu.reset();
            if (col[0] == col[1])
              dsu.merge(3, 4);
            if (col[0] == col[2])
              dsu.merge(3, 5);
            if (col[1] == col[2])
              dsu.merge(4, 5);
            for (int z = 0; z < 3; ++z) {
              if (mask & (1 << z)) {
                dsu.merge(z, z+3);
              }
            }
            int ada = 0;
            for (int z = 0; z < 3; ++z) {
              if (k & (1 << col[z])) {
                ada |= 1 << dsu.find(3+z);
              }
            }
            for (int z = 0; z < 3; ++z) {
              if (employee[i] & (1 << z)) {
                ada |= 1 << dsu.find(z);
              }
            }
            if (i <= last && ada > 7) continue;
            if (i > last && ada > 7 && __builtin_popcount(ada) > 1) continue;
            ada &= 7;
            int state = 0;
            for (int z = 2; z >= 0; --z) {
              state = state * 3 + dsu.find(z);
            }
            upd(dp[cur][state][ada], now + cost[mask]);
          }
        }
      }
    }

    for (int mask = 0; mask < 4; ++mask) {
      cost[mask] = 0;
      for (int z = 0; z < 2; ++z)
        if (mask & (1 << z))
          cost[mask] += b[z][i];
    }
    for (int j = 0; j < 27; ++j) {
      int x = j;
      for (int z = 0; z < 3; ++z) {
        col[z] = x % 3;
        x /= 3;
      }
      for (int k = 0; k < 8; ++k) {
        long long now = dp[cur][j][k];
        if (now >= inf) continue;
        for (int mask = 0; mask < 4; ++mask) {
          dsu.reset();
          if (col[0] == col[1])
            dsu.merge(0, 1);
          if (col[0] == col[2])
            dsu.merge(0, 2);
          if (col[1] == col[2])
            dsu.merge(1, 2);
          for (int z = 0; z < 2; ++z) {
            if (mask & (1 << z)) {
              dsu.merge(z, z+1);
            }
          }
          int state = 0;
          for (int z = 2; z >= 0; --z) {
            state = state * 3 + dsu.find(z);
          }
          int ada = 0;
          for (int z = 0; z < 3; ++z) {
            if (employee[i] & (1 << z)) {
              ada |= 1 << dsu.find(z);
            }
          }
          for (int z = 0; z < 3; ++z) {
            if (k & (1 << col[z])) {
              ada |= 1 << dsu.find(z);
            }
          }
          upd(dp[cur][state][ada], now + cost[mask]);
        }
      }
    }
  }
  long long ans = inf;
  for (int i = 0; i < 27; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (__builtin_popcount(j) <= 1) {
        upd(ans, dp[cur][i][j]);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
