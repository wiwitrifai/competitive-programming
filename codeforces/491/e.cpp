#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int cnt[N];
long long dp[N][N], C[N][N];

long long solve(int d, int s) {
  if (d > 9) return s == 0;
  if (cnt[d] == 0) return solve(d+1, s);
  long long & ret = dp[d][s];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 1; i <= cnt[d]; ++i) {
    if (i > s) break;
    long long bef = solve(d+1, s-i);
    if (d > 0)
      ret += C[s][i] * bef;
    else if (d == 0 && s > i)
      ret += C[s-1][i] * bef;
  }
  return ret;
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]);
  }
  long long n;
  cin >> n;
  int k = 0;
  while (n) {
    ++k;
    ++cnt[n % 10];
    n /= 10;
  }
  memset(dp, -1, sizeof dp);
  long long ans = 0;
  for (int i = 1; i <= k; ++i)
    ans += solve(0, i);
  cout << ans << endl;
  return 0;
}