#include <bits/stdc++.h>

using namespace std;

const int N = 55, mod = 998244353;

long long powmod(long long b, long long p) {
  b %= mod;
  if (b < 0) b += mod;
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int dp[N][N][N][N];
int w[N];
int like[N];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", like+i);
  }
  long long sum = 0, slike= 0, shate = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", w+i), sum += w[i];
    if (like[i])
      slike += w[i];
    else
      shate += w[i];
  }
  for (int i = 0; i < n; ++i) {
    dp[i][0][0][0] = 1;
    if (like[i]) {
      for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= j; ++k) {
          for (int x = 0; x <= k; ++x) {
            int & now = dp[i][j][k][x];
            // cerr << i << " " << j << " " << k << " " << x << " = " << now << endl;
            if (now == 0) continue;
            long long den = 1LL * powmod(sum + k - (j - k), mod-2) * now % mod;
            long long nom = w[i] + x;
            long long p = 1LL * nom * den % mod;
            add(dp[i][j+1][k+1][x+1], p);

            nom = (slike - w[i] + k - x);
            p = 1LL * nom * den % mod;
            add(dp[i][j+1][k+1][x], p);

            nom = (shate - (j - k));
            p = 1LL * nom * den % mod;
            add(dp[i][j+1][k][x], p);
          }
        }
      }
    }
    else {
      for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= j; ++k) {
          for (int x = 0; x <= k; ++x) {
            int & now = dp[i][j][k][x];
            if (now == 0) continue;
            long long den = 1LL * powmod(sum - k + (j - k), mod-2) * now % mod;
            long long nom = w[i] - x;
            if (nom < 0) continue;
            long long p = 1LL * nom * den % mod;
            add(dp[i][j+1][k+1][x+1], p);

            nom = (shate - w[i] - k + x);
            p = 1LL * nom * den % mod;
            add(dp[i][j+1][k+1][x], p);

            nom = (slike + j - k);
            p = 1LL * nom * den % mod;
            add(dp[i][j+1][k][x], p);
          }
        }
      }
    }
    long long ans = 0;
    if (like[i]) {
      for (int k = 0; k <= m; ++k) {
        for (int x = 0; x <= k; ++x) {
          int now = dp[i][m][k][x];
          ans = (ans + 1LL * now * (w[i] + x)) % mod;
          // cerr << k << " " << x << " " << now << endl;
        }
      }
    }
    else {
      for (int k = 0; k <= m; ++k) {
        for (int x = 0; x <= k; ++x) {
          int now = dp[i][m][k][x];
          ans = (ans + 1LL * now * (w[i] - x)) % mod;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
