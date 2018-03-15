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
  int n, m, status; // -2 : not started, -1 : fail, 0 : ok, 1 : infinity;
  vector<int> left, up, pos;
  simplex() {}

  void set(VVD & A, VD & B, VD & C) {
    n = C.size(); m = A.size(); left.resize(m);
    up.resize(n); pos.resize(n); res.resize(n);
    status = -2; v = 0; a = A; b = B; c = C;
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
