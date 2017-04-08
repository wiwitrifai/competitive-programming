#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7, MAGIC = 25;
int tmp[N][N];

struct matrix {
  int n, m;
  int x[N][N];
  matrix(int n = 1000, int m = 1) : n(n), m(m) {};
  void rmul(matrix & other) {
    for (int i = 0; i < other.n; i++) {
      for (int j = 0; j < m; j++) {
        int now = 0;
        for (int k = 0; k < n; k++) {
          now = (now + 1LL * other.x[i][k] * x[k][j]) % mod;
        }
        tmp[i][j] = now;
      }
    }
    n = other.n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        x[i][j] = tmp[i][j];
  }
};

matrix A, B, C, L, R;
int main() {
  int n;
  scanf("%d", &n);
  A.n = A.m = B.n = B.m = C.n = C.m = L.n = R.n = n;
  L.m = R.m = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", A.x[i]+j);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", B.x[i]+j);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", C.x[i]+j);
  }
  bool ok = 1;
  srand(time(NULL));
  for (int it = 0; it < MAGIC; it++) {
    for (int i = 0; i < n; i++) {
      L.x[i][0] = R.x[i][0] = (rand() % 1000) >= 500;
    }
    L.rmul(B);
    L.rmul(A);
    R.rmul(C);
    for (int i = 0; i < n; i++) {
      if (L.x[i][0] != R.x[i][0]) {
        ok = 0;
        break;
      }
    }
    if (!ok)
      break;
  }
  puts(ok ? "YES" : "NO");
  return 0;
}