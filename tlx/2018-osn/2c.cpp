#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7, LG = 22;
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

long long dp[22][N];
int a[N];
int sp[LG][N];

int get(int l, int r) {
  int len = r - l;
  int lg = 31 - __builtin_clz(len);
  return gcd(sp[lg][l], sp[lg][r-(1<<lg)]);
}


int main() {
  scanf("%*s");
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  dp[0][0] = 1;
  for (int j = 0; j < k; ++j) {
    long long sum = 0, add = 0;
    for (int i = 0; i <= n; ++i) {
      sum = (sum + add) % mod;
      dp[j+1][i] = sum;
      add = (add + dp[j][i]) % mod;
    }
  }
  for (int i = 0; i <= k; ++i) {
    long long sum = 0;
    for (int j = 0; j <= n; ++j) {
      long long cur = dp[i][j];
      sum = (cur + sum) % mod;
      dp[i][j] = sum;
    }
    sum = 0;
    for (int j = 0; j <= n; ++j) {
      long long cur = dp[i][j];
      sum = (cur + sum) % mod;
      dp[i][j] = sum;
    }
  }
  for (int i = 0; i < n; ++i)
    sp[0][i] = a[i];
  for (int j = 0; j+1 < LG; ++j) {
    for (int i = 0; i+(1 << (j+1)) <= n; ++i)
      sp[j+1][i] = gcd(sp[j][i], sp[j][i+(1<<j)]);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int l =  i+1;
    while (l <= n) {
      int r = n;
      int cur = get(i, l);
      int from = l;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        int val = get(i, mid);
        if (val == cur)
          l = mid;
        else
          r = mid-1;
      }
      for (int j = 0; j < k; ++j) {
        long long now = 1LL * (dp[k-j-1][i] - (i ? dp[k-j-1][i-1] : 0)) * cur % mod;
        ans = (ans +  1LL * now * (dp[j][n-from] - ((n-l-1) < 0 ? 0 : dp[j][n-l-1]))) % mod;
      }
      ++l;
    }
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}