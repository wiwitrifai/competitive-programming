#include <bits/stdc++.h>

using namespace std;
 
typedef long double LD;
typedef vector<LD> VD;
typedef vector<VD> VVD;

const LD EPS = 1e-9;

inline bool eq(LD a, LD b) { return fabs(a - b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }

struct simplex {
  VVD a;
  VD b, c, res;
  LD v;
  int n, m;
  vector<int> left, up, pos;
  int status; // -2 : not started, -1 : fail, 0 : ok, 1 : infinity;
  simplex() {}

  void set(VVD & A, VD & B, VD & C) {
    n = C.size();
    m = A.size();
    left.resize(m);
    up.resize(n);
    pos.resize(n);
    res.resize(n);
    status = -2;
    v = 0;
    a = A;
    b = B;
    c = C;
  }

  void pivot(int x, int y) {
    swap(left[x], up[y]);
    LD k = a[x][y];
    a[x][y] = 1;
    b[x] /= k;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      a[x][i] = a[x][i] / k;
      if (!eq(a[x][i], 0))
        pos[cur++] = i;
    }
    
    for (int i = 0; i < m; i++) {
      if (i == x || eq(a[i][y], 0)) continue;
      LD cof = a[i][y];
      b[i] -= cof * b[x];
      a[i][y] = 0;
      for (int j = 0; j < cur; j++)
        a[i][pos[j]] -= cof * a[x][pos[j]];
    }
    LD cof = c[y];
    v += cof * b[x];
    c[y] = 0;
    for (int i = 0; i < cur; i++) {
      c[pos[i]] -= cof * a[x][pos[i]];
    }
  }

  void solve() {
    for (int i = 0; i < n; i++)
      up[i] = i;
    for (int i = 0; i < m; i++)
      left[i] = i + n;

    while (1) {
      int x = -1;
      for (int i = 0; i < m; i++)
        if (lt(b[i], 0) && (x == -1 || b[i] < b[x])) {
          x = i;
        }
      if (x == -1) break;
      int y = -1;
      for (int j = 0; j < n; j++)
        if (lt(a[x][j], 0)) {
          y = j; 
          break;
        }
      if (y == -1) {
        status = -1;
        return;
        assert(false); // no solution
      }
      pivot(x, y);
    }
    while (1) {
      int y = -1;
      for (int i = 0; i < n; i++)
          if (lt(0, c[i])  && (y == -1 || (c[i] > c[y]))) {
              y = i;
          }
      if (y == -1) break;
      
      int x = -1;
      for (int i = 0; i < m; i++) {
          if (lt(0, a[i][y])) {
              if (x == -1 || (b[i] / a[i][y] < b[x] / a[x][y])) {
                  x = i;
              } 
          }
      }
      if (y == -1) {
          status = 1;
          return;
          assert(false); // infinite solution
      }
      pivot(x, y);
    }

    res.assign(n, 0);

    for (int i = 0; i < m; i++) {
        if (left[i] < n) {
            res[left[i]] = b[i];
        }
    }
    status = 0;
  }
  // HOW TO USE ::
  // -- call init(n, m)
  // -- call solve()
  // -- variables in "up" equals to zero 
  // -- variables in "left" equals to b
  // -- max: c * x
  // -- b[i] >= a[i] * x
  // -- answer in "v"
  // -- sertificate in "res"
};

const int N = 33;
int g[N][N], di[N][N], id[N][N];
int to[N][N];

int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", g[i]+j), to[i][j] = j, di[i][j] = g[i][j];
      if (g[i][j] > 0) {
        id[i][j] = cnt++;
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][k] < 0 || g[k][j] < 0) continue;
        if (g[i][j] < 0 || g[i][j] > g[i][k] + g[k][j]) {
          g[i][j] = g[i][k] + g[k][j];
          to[i][j] = to[i][k];
        }
      }
    }
  }
  VVD A;
  VD B;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (di[i][j] <= 0) continue;
      VD cur(cnt, 0);
      cur[id[i][j]] = 1;
      A.push_back(cur);
      B.push_back(1 * di[i][j]);
    }
  }
  int r;
  scanf("%d", &r);
  for (int i = 0; i < r; ++i) {
    int s, d, t;
    scanf("%d %d %d", &s, &d, &t);
    t -= g[s][d];
    VD cur(cnt, 0);
    while (s != d) {
      int v = to[s][d];
      cur[id[s][v]] = 1;
      s = v;
    }
    A.push_back(cur);
    B.push_back(t + EPS);
    for (int j = 0; j < cnt; ++j)
      cur[j] *= -1;
    A.push_back(cur);
    B.push_back(-t + EPS);
  }
  int q;
  scanf("%d", &q);
  simplex solver;
  for (int i = 0; i < q; ++i) {
    int s, d;
    scanf("%d %d", &s, &d);
    LD low = g[s][d], up = g[s][d] * 2;
    if (g[s][d] != 0) {
      VD x(cnt), c(cnt);
      int now = s;
      while (now != d) {
        int v = to[now][d];
        c[id[now][v]] = 1;
        now = v;
      }
      solver.set(A, B, c);
      solver.solve();
      if (solver.status == 0) up = solver.v + g[s][d];
      for (int j = 0; j < cnt; ++j)
        c[j] *= -1;
      solver.set(A, B, c);
      solver.solve();
      if (solver.status == 0) low = -solver.v + g[s][d];
    }
    printf("%d %d %.20lf %.20lf\n", s, d, (double)low, (double)up);
  }
  return 0;
}