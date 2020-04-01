#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
  ull b, m;
  FastMod(ull tb) : b(tb), m(ull((L(1) << 64) / b)) {}
  ull reduce(ull a) {
    ull q = (ull)((L(m) * a) >> 64);
    ull r = a - q * b; // can be proven that 0 <= r < 2*b
    return r >= b ? r - b : r;
  }
  ull powmod(ull x, ull p) {
    ull r = 1;
    for (; p; p >>= 1, x = reduce(x * x))
      if (p & 1)
        r = reduce(r * x);
    return r;
  }
};

const int N = 7505;

int prim[N], P[N][N];

long long dp[N][2], sum[N];

int main() {
  const string prob = "exercise";
  freopen((prob + ".in").c_str(), "r", stdin);
  freopen((prob + ".out").c_str(), "w", stdout);

  int n, mod;
  scanf("%d %d", &n, &mod);
  int totient = mod-1;
  FastMod fmod(mod), ftotient(mod-1);

  for (int i = 0; i <= n; ++i) {
    P[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      P[i][j] = ftotient.reduce((ull)P[i][j-1] * (i - j + 1));
    }
  }

  for (int i = 2; i < N; ++i) {
    if (prim[i]) continue;
    for (int j = i; j < N; j += i) {
      if (prim[j])
        prim[j] = -1;
      else
        prim[j] = i;
    }
  }
  long long ans = 1;
  for (int x = 2; x <= n; ++x) {
    if (prim[x] == -1) continue;
    fill(sum, sum+x, 0);
    dp[0][0] = 1;
    dp[0][1] = 0;
    sum[0] = 1;
    long long sum_1 = 0, sum_0 = 1;
    for (int i = 1, r = 1; i <= n; ++i, ++r) {
      if (r == x) r = 0;
      if (i >= x)
        sum[r] = ftotient.reduce(sum[r] * P[i-1][x-1]);
      dp[i][0] = sum_0 - sum[r];
      if (dp[i][0] < 0)
        dp[i][0] += totient;
      dp[i][1] = sum_1 + sum[r];
      if (dp[i][1] >= totient)
        dp[i][1] -= totient;
      sum_1 = ftotient.reduce(sum_1 * i + dp[i][1]);
      sum_0 = ftotient.reduce(sum_0 * i + dp[i][0]);
      sum[r] = ftotient.reduce(sum[r] * i + dp[i][0]);
    }
    ans = fmod.reduce(ans * fmod.powmod(prim[x], dp[n][1]));
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);

  fclose(stdin);
  fclose(stdout);
  return 0;
}
