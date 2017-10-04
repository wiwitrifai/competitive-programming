#include <bits/stdc++.h>

using namespace std;

const long long inf = (1LL << 61) + 7;
const int N = 62;

long long dp[N][N], C[N][N];

long long f(int n, int k) {
  if (n == 0)
    return !k;
  long long & ret = dp[n][k];
  if (ret != -1)
    return ret;
  ret = f(n-1, k+1);
  if (k > 0)
    ret += f(n-1, k-1);
  if (ret >= inf) ret = inf;
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
      if (C[i][j] > inf)
        C[i][j] = inf;
    }
  }
  int n;
  long long k;
  cin >> n >> k;
  n *= 2;
  int b = 0, open = 0;
  bool ok = 1;
  for (int i = 0; i < n; i++) {
    long long v = open >= n/2 ? 0 : C[n-1-i][n/2-open-1];
    if (ok && open+1 <= n/2)
      v -= f(n-i-1, b+1);
    // cerr << v << " " << k << endl;
    if (i-open < n/2 && (k > v || open >= n/2)) {
      k -= v;
      b--;
      printf(")");
    }
    else {
      b++;
      open++;
      printf("(");
    }
    ok &= b >= 0;
  }
  printf("\n");
  return 0;
}