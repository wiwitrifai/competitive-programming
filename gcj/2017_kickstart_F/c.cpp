#include <bits/stdc++.h>

using namespace std;

const int N = 105, inf = 1e9;
struct matrix {
  int n, m;
  double _mat[N][N];
  matrix(int n, int m) : n(n), m(m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        _mat[i][j] = 0;
  }
  void reset() {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        _mat[i][j] = (i == j);
  }
  const double * operator[](const int id) const {
    return _mat[id];
  }
  double * operator[](const int id) {
    return _mat[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i<this->n; i++) {
      for(int j = 0; j<mat.m; j++) {
        double &now = ret[i][j];
        now = 0;
        for(int k = 0; k<this->m; k++) {
          now = (now + this->_mat[i][k] * mat[k][j]);
        }
      }
    }
    return ret;
  }
  void print() {
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<m; j++)
        cout << _mat[i][j] << " ";
      cout << endl;
    }
  }
  matrix operator^(long long pw) const {
    matrix ret(n, m), base = *this;
    ret.reset();
    while(pw) {
      if(pw & 1)
        ret = ret*base;
      base = base*base;
      pw >>= 1;
    }
    return ret;
  }
};

int d[N][N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        d[i][j] = (i == j) ? 0 : inf;
      }
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      d[u][v] = min(d[u][v], w);
      d[v][u] = min(d[v][u], w);
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    matrix b(n+1, n+1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        b[i][j] = (i == j) ? 0 : (double)1.0/(n-1);
    }
    b[n][n] = 1;
    for (int i = 0; i < n; i++) {
      long long sum = 0;
      for (int j = 0; j < n; j++)
        sum += d[i][j];
      b[i][n] = (double)sum/(n-1);
    }
    matrix a(n+1, 1);
    a[n][0] = 1;
    matrix ans = (b ^ p) * a;
    printf("Case #%d: %.20lf\n", tc, ans[0][0]);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}