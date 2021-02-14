// unfinished!

#include <bits/stdc++.h>

using namespace std;

const int mod = 99824435, N = 44;

long long dp[N][N], C[N][N];

void upd(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

long long rec(int n, int m) {
  if (n == 1) {
    return m == 0 ? 1 : 0;
  }
  if (m < n-1) return 0;
  long long & ret = dp[n][m];
  if (ret != -1) return ret;
  ret = rec(n, m-1);
  for (int u = 1; u < n; ++i) {
    for (int e = 0; e < m; ++e) {
      long long cur = rec(u, e) * rec(n-u, m-e-1) % mod;
      cur = cur * C[n-2][u-1] % mod;
      cur = cur * C[m-1][e] % mod;
      upd(ret, cur);
    }
  }
  ret = ret * C[n][2] % mod;
  return ret;
}

long long memd[N];

long long disjoint(int m) {
  long long & ans = memd[m];
  if (ans != -1)
    return ans;
  ans = 0;
  for (int u = 1; u < n; ++u) {
    for (int v = 1; v + u <= n; ++v) {
      for (int eu = 0; eu <= m; ++eu) {
        for (int ev = 0; ev + eu <= m; ++ev) {
          long long cur = rec(u, eu) * rec(v, ev) % mod;
          cur = cur * C[eu+ev][eu] % mod;
          cur = cur * C[m][eu+ev] % mod;
          cur = cur * C[u+v-2][u-1] % mod;
          cur = cur * C[n-2][u+v-2] % mod;
          cur = cur * powmod(C[n-u-v][2], m-eu-ev) % mod;
          upd(ans, cur);
        }
      }
    }
  }
  return ans;
}


long long conn[N][N][N];

long long rconn(int n, int m, int b) {
  long long & ret = conn[n][m][b];
  if (b == 0)
    return rec(n, m);
  ret = 0;
  if (b == 1) {
    for (int u = 1; u < n; ++u) {
      int v = n - u;
      for (int eu = 0; eu <= m; ++eu) {
        for (int ev = 0; ev + eu + 1 <= m; ++ev) {
          long long cur = rec(u, eu) * rec(v, ev) % mod;
          cur = cur * C[eu+ev][eu] % mod;
          cur = cur * C[m-1][eu+ev] % mod;
          cur = cur * C[u+v-2][u-1] % mod;
          cur = cur * C[n-2][u+v-2] % mod;
          cur = cur * u % mod;
          cur = cur * v % mod;
          cur = cur * powmod(C[n-u-v][2], m-eu-ev) % mod;
          upd(ans, cur);
        }
      }
    }
  }
  for (int u = 1; u < n; ++i) {
    for (int e = 0; e+2 <= m; ++e) {
      long long cur = rconn(u, e, b-1) * rec(n-u, m-e-2) % mod;
      cur = cur * C[n][u] % mod;
      cur = cur * C[m-1][e] % mod;
      upd(ret, cur);
    }
  }
}

int main() {
  memset(dp, -1, sizeof dp);
  memset(memd, -1, sizeof memd);
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
  }
  int n, m, a, b, c;
  scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
  return 0;
}
