#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5, M = 121, G = 505;
const int mod = 1e9 + 7;
struct matrix {
  int n, m;
  long long _mat[10][10];
  matrix(int n = 10, int m = 10) : n(n), m(m) {
  }
  void reset() {
    memset(_mat, 0, sizeof _mat);
    for(int i = 0; i<n; i++)
      _mat[i][i] = 1;
  }
  const long long * operator[](const int id) const {
    return _mat[id];
  }
  long long * operator[](const int id) {
    return _mat[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i<this->n; i++) {
      for(int j = 0; j<mat.m; j++) {
        long long &now = ret[i][j];
        now = 0;
        for(int k = 0; k<this->m; k++) {
          now = (now + this->_mat[i][k] * mat[k][j]) % mod;
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
};

matrix init[10];
matrix mul[G][G];
char s[N];
matrix cur;

int main() {
  int n, q;
  scanf("%s", s);
  n = strlen(s);
  scanf("%d", &q);
  for (int i = 0; i < 10; i++) {
    init[i].reset();
    for (int j = 0; j < 10; j++)
      init[i][j][i] = 1;
  }
  int m = 0;
  for (int i = 0; i < n; i += M, m++) {
    mul[m][m].reset();
    for (int j = 0; j < M && i+j < n; j++) {
      mul[m][m] = mul[m][m] * init[s[i+j]-'a'+1];
    }
  }
  for (int len = 1; len < m; len++) {
    for (int i = 0; i+len < m; i++)
      mul[i][i+len] = mul[i][i+len-1] * mul[i+len][i+len];
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--; r--;
    cur.n = 10;
    cur.m = 1;
    for (int j = 0; j < 10; j++)
      cur[j][0] = j != 0;
    while (r >= l && ((r+1) % M)) {
      int id = s[r]-'a'+1;
      for (int j = 0; j < 10; j++) {
        if (j == id) continue;
        cur[j][0] += cur[id][0];
        if (cur[j][0] >= mod) cur[j][0] -= mod;
      }
      r--;
    }
    if (l > r) {
      cur[0][0] %= mod;
      if (cur[0][0] < 0)
        cur[0][0] += mod;
      printf("%d\n", (int)cur[0][0]);
    }
    else {
      int gl = l/M;
      if (l % M)
        gl++;
      if (gl <= r/M) {
        cur = mul[gl][r/M] * cur;
      }
      gl *= M;
      gl--;
      while (l <= gl) {
        int id = s[gl]-'a'+1;
        for (int j = 0; j < 10; j++) {
          if (j == id) continue;
          cur[j][0] += cur[id][0];
          if (cur[j][0] >= mod) cur[j][0] -= mod;
        }
        gl--;
      }
      cur[0][0] %= mod;
      if (cur[0][0] < 0)
        cur[0][0] += mod;
      printf("%d\n", (int)cur[0][0]);
    }
  }
  return 0;
}