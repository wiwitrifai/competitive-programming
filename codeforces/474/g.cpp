#include <bits/stdc++.h>

using namespace std;

const int N = 101;

long long C[N][N], fac[N];

long long F[N][N];

long long rec(int n, int k) {
  if (n < k) return 0;
  if (n == 0) return 1;
  if (k == 1) return fac[n-1];
  if (k == 0) return 0;
  if (F[n][k] != -1) return F[n][k];
  long long & ret = F[n][k];
  ret = (n-1) * rec(n-1, k) + rec(n-1, k-1);
  return ret;
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }
  fac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = fac[i-1] * i;
  memset(F, -1, sizeof F);
  for (int n = 1; n <= 20; ++n) {
    for (int k = 1; k <= n; ++k)
      cerr << rec(n, k) << " ";
    cerr << " = " << fac[n] << endl;
  }
  return 0;
}