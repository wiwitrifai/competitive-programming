#include <bits/stdc++.h>

using namespace std;

const int N = 303;

int n, m, k, pk[N];

int C[N][N], dp[N][N], val[N][N];

int main() {
  cin >> n >> k >> m;
  pk[0] = 1;
  for (int i = 1; i < N; ++i) {
    pk[i] = 1LL * pk[i-1] * k % m;
  }
  for (int i = 0; i < N; ++i)
    val[0][i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      val[i][j] = val[i][j-1];
      for (int z = 1; z <= i; ++z) {
        int cur = 1;
        if (i-z > 0)
          cur = cur * (k-j) % m;
        if (i-z > 1)
          cur = cur * pk[i-z-1] % m;
        val[i][j] = (val[i][j] + cur) % m;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % m;
  }
  dp[0][0] = 1;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % m;
      dp[i][j] = 1LL * dp[i][j] * j % m;
      for (int z = 1; z+j-1 <= k; ++z) {
        long long cur = 1LL * dp[i][j] * C[k-z][j-1] % m;
        cur = cur * val[n-i][z-1] % m;
        cur = cur * C[n-1][i-1] % m;
        // cerr << i << " " << j << " " << z << " = "<< cur << " " << dp[i][j] << endl;
        ans = (ans + cur) % m;
      }
    }
  }
  cout << ans << endl;
  return 0;
}