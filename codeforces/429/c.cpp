#include <bits/stdc++.h>

using namespace std;

const int N = 403, mod = 1e9 + 7;

long long dp[N][N], C[2 * N][2 * N], fac[2 * N];
int a[N], n;

void add(long long &le, long long ri) {
  le += ri;
  if (le >= mod)
    le -= mod;
}


int main() {
  fac[0] = 1;
  for (int i = 1; i < 2 * N; i++)
    fac[i] = (fac[i-1] * i) % mod;
  for (int i = 0; i < 2 * N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    int now = 1;
    for (long long j = 2; j * j <= a[i]; j++) if ((a[i] % j) == 0) {
      int q = 0;
      while ((a[i] % j) == 0) {
        q ^= 1;
        a[i] /= j;
      }
      if (q)
        now *= j;
    }
    now *= a[i];
    a[i] = now;
  }
  sort(a, a+n);
  vector<int> pp;
  int now = a[0], cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == now)
      cnt++;
    else {
      pp.push_back(cnt);
      cnt = 1;
      now = a[i];
    }
  }
  if (cnt)
    pp.push_back(cnt);
  dp[0][0] = 1;
  now = 0;
  for (int i = 0; i < pp.size(); i++) {
    int p = pp[i];
    for (int j = 0; j <= now; j++) {
      if (dp[i][j]) {
        long long ck = dp[i][j] * fac[p] % mod;
        for (int k = 1; k <= min(p, now+1); k++) {
          long long cur = (C[p-1][k-1] * ck) % mod;
          for (int w = 0; w <= min(k, j); w++) {
            int z = (j - w) + (p-k);
            add(dp[i+1][z], (cur * C[j][w] % mod) * C[now+1-j][k-w] % mod);
          }
        }
      }
    }
    now += pp[i];
  }
  cout << dp[pp.size()][0] << endl;
  return 0;
}