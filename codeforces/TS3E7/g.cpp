#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 102;

long long dp[N][1<<10];
long long cnt[1<<10][N], C[N][N];
int v[12];

long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    p >>=1;
    b = (b * b) % mod;
  }
  return ret;
}
long long inv[N];

int main() {
  inv[0] = 0;
  inv[1] = 1;
  for (int i = 2; i < N; i++)
    inv[i] = powmod(i, mod-2);
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  a--;
  int m = 0;
  for (int i = 2; 1LL * i * i < k; i++) if ((k % i) == 0) {
    v[m] = 1;
    while ((k % i) == 0) {
      k /= i;
      v[m] *= i;
    }
    m++;
  }
  if (k > 1) {
    v[m++] = k;
  }
  int all = (1<<m);
  for (int i = 0; i < all; i++) {
    int now = 1;
    for (int j = 0; j < m; j++)
      if (i & (1<<j))
        now *= v[j];
    cnt[i][0] = b/now - a/now;
  }
  // for (int i = 0; i < m; i++)
  //   cerr << v[i] << " ";
  // cerr << endl;
  for (int i = all-1; i >= 0; i--) {
    for (int j = (i-1) & i; j > 0; j = (j-1) & i)
      cnt[j][0] -= cnt[i][0];
    if (i != 0)
      cnt[0][0] -= cnt[i][0];
    cnt[i][1] = cnt[i][0];
    // cerr << cnt[i][1] << " ";
    for (int j = 2; j <= n; j++) {
      cnt[i][j] = (cnt[i][j-1] * (((cnt[i][0]-j+1) * inv[j]) % mod)) % mod;
      // cerr << cnt[i][j] << " ";
    }
    // cerr << endl;
  }
  dp[0][0] = 1;
  int to = 1;
  for (int i = 0; i < all; i++) {
    if (cnt[i][0] == 0) continue;
    while (to <= i)
      to <<= 1;
    for (int j = n-1; j >= 0; j--) {
      for (int mask = to-1; mask >= 0; mask--) {
        for (int z = j+1; z <= n; z++) {
          int nx = mask | i;
          dp[z][nx] = (dp[z][nx] + dp[j][mask] * cnt[i][z-j]) % mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + C[n-1][i-1] * dp[i][all-1]) % mod;
  } 
  cout << ans << endl;
  return 0;
}