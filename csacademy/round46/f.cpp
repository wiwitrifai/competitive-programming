#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7;
const long long inv2 = (mod+1)/2;

long long pw[N * 2];
long long dp[N][N][2][2];
int up[N][N], down[N][N];
char s[N][N];

long long add(long long &le, long long val) {
  le += val;
  if (le >= mod)
    le -= mod;
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < 2 * N; i++)
    pw[i] = pw[i-1] * 2 % mod;
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  a--; b--;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int j = 0; j < m; j++) {
    int now = 0;
    for (int i = 0; i < n; i++) {
      up[i][j] = now;
      now += s[i][j] == '?';
    }
    now = 0;
    for (int i = n-1; i >= 0; i--) {
      down[i][j] = now;
      now += s[i][j] == '?';
    }
  }
  dp[a][0][0][0] = 1;
  for (int j = 0; j < m; j++) {
    // 0, 0
    long long tot = 0;
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '1') continue;
      long long & cur = dp[i][j][0][0];
      int k;
      long long val;
      if (cur == 0) continue;
      // atas
      if (i) {
        k = down[i][j];
        val = cur * pw[k] % mod;
        if (i && s[i-1][j] == '1')
          val = 0;
        add(dp[i-1][j][0][1], cur * pw[down[i][j]] % mod);
      }
      // kanan
      k = up[i][j] + down[i][j];
      if (i && s[i-1][j] == '?') k--;
      val = cur * pw[k] % mod;
      if (i && s[i-1][j] == '0')
        val = 0;
      add(dp[i][j+1][0][0], val);
      // bawah
      add(dp[i][j+1][1][0], tot);
      k = up[i][j+1] + up[i][j] + down[i][j];
      if (j+1 < m && s[i][j+1] == '0')
        tot = 0;
    }
  }  
  return 0;
}