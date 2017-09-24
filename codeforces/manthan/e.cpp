#include <bits/stdc++.h>

using namespace std;

// base, tempat, mask
long long dp[11][65][1 << 11];
// tanpa leading zero
long long dp2[11][65][2];

void add(long long &le, long long ri) {
  le += ri;
}
int s[66];
long long get(long long n, int b) {
  int m = 0;
  while (n) {
    s[m++] = n % b;
    n /= b;
  }
  if (m == 0)
    s[m++] = 0;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    ans += dp2[b][i][0];
  }
  int all = (1 << b) -1;
  for (int i = 1; i < s[m-1]; i++)
    ans += dp[b][m-1][(1<<i)];
  int mask = (1 << s[m-1]);
  for (int id = m-2; id >= 0; id--) {
    for (int j = 0; j < s[id]; j++) {
      int cur = mask ^ (1 << j);
      ans += dp[b][id][cur];
    }
    mask ^= (1 << s[id]);
  }
  return ans;
}

long long C[100][100];

int main() {
  for (int i = 0; i < 100; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }
  for (int b = 2; b <= 10; b++) {
    dp[b][0][0] = 1;
    for (int it = 0; it < b; it++) {
      for (int tempat = 63; tempat >= 0; tempat--) {
        int tot = 1 << it;
        for (int mask = 0; mask < tot; mask++) {
          if (dp[b][tempat][mask] == 0) continue;
          for (int j = 1; j + tempat < 64; j++)
            add(dp[b][j+tempat][mask | ((j&1) << it)], dp[b][tempat][mask] * C[tempat+j][j]);
        }
      }
    }
    for (int i = 0; i < 64; i++) {
      for (int z = 0; z < 2; z++) {
        dp2[b][i][z] = dp[b][i][z];
        if (dp2[b][i][z] == 0) continue;
        int mask = z;
        for (int j = i-1; j >= 0; j--) {
          mask ^= 1;
          dp2[b][i][z] -= dp2[b][j][mask];
        }
      }
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int b;
    long long l, r;
    scanf("%d %lld %lld", &b, &l, &r);
    long long ans = get(r+1, b) - get(l, b);
    printf("%lld\n", ans);
  }
  return 0;
}