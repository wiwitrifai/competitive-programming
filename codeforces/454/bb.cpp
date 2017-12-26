#include <bits/stdc++.h>

using namespace std;
int x[100][100];

bool neigh[100][100];

bool cek(int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i && neigh[x[i][j]][x[i-1][j]]) return false;
      if (j && neigh[x[i][j]][x[i][j-1]]) return false;
    }
  }
  return true;
}

int ans[10][10][100];
int a[100];

int main() {
  for (int n = 1; n < 4; ++n) {
    for (int m = 1; m <= 5; ++m) {
      for (int i = 0; i < n * m; ++i)
        a[i] = i;
      for (int i = 0; i < n * m; ++i)
        for (int j = 0; j < n * m; ++j)
          neigh[i][j] = 0;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          x[i][j] = i * m + j;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (i) {
            neigh[x[i][j]][x[i-1][j]] = 1;
            neigh[x[i-1][j]][x[i][j]] = 1;
          }
          if (j) {
            neigh[x[i][j]][x[i][j-1]] = 1;
            neigh[x[i][j-1]][x[i][j]] = 1;
          }
        }
      }
      bool ok = 0;
      do {
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
            x[i][j] = a[i * m + j];
        if (cek(n, m)) {
          ok = 1;
          break;
        }
      } while (next_permutation(a, a+n * m));
      cout << n << " " << m << " = " << ok << endl;
      if (ok) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j< m; ++j)
            cout << x[i][j] << " ";
          cout << endl;
        }
      }
    }
  }

  return 0;
}