#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

const int N = 255, mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int dp[2][N][N][3];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  open_file("khoshaf.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, l, r;
    scanf("%d %d %d %d", &n, &k, &l, &r);
    if (n > 250) {
      puts("0");
      continue;
    }
    int cnt[3];
    memset(cnt, 0, sizeof cnt);
    --l;
    for (int i = 0; i < 3; ++i) {
      if (r >= i) {
        cnt[i] = (r-i) / 3 + 1;
      }
      if (l >= i) {
        cnt[i] -= (l-i) / 3 + 1;
      }
    }
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        for (int z = 0; z < 3; ++z)
          dp[0][i][j][z] = dp[1][i][j][z] = 0; 
    int c = 0, b = 1;
    dp[c][0][0][0] = 1;
    for (int it = 0; it < n; ++it) {
      swap(c, b);
      for (int i = 0; i <= n;++i)
        for (int j = 0; j <= n; ++j)
          for (int z = 0; z < 3; ++z)
            dp[c][i][j][z] = 0;
      for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
          for (int z = 0; z < 3; ++z) {
            if (dp[b][i][j][z] == 0) continue;
            for (int y = 0; y < 3; ++y) {
              int ii = i, jj = j, zz = z + y;
              if (zz >= 3) zz -= 3;
              if (zz == 0)
                ++ii;
              else if (zz == 1)
                ++jj;
              add(dp[c][ii][jj][zz], 1LL * dp[b][i][j][z] * cnt[y] % mod);
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      int cur_0 = i * (i + 1) / 2;
      if (cur_0 > k) continue;
      for (int j = 0; j <= n; ++j) {
        if (i + j > n) continue;
        int z = n - i - j;
        int cur = cur_0 + j * (j - 1) / 2 + z * (z - 1) / 2;
        if (cur != k) continue;
        for (int y = 0; y < 3; ++y) {
          add(ans, dp[c][i][j][y]);
        }
      }
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%d\n", ans);
  }
  close_file();
  return 0;
}