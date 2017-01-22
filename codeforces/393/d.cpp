#include <bits/stdc++.h>

using namespace std;

const int N = 5050, mod = 1e9 + 7;
char s[N], ss[N];
long long dp[N][N];
long long sum[26];
bool ok[26];


int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++)
    s[i] -= 'a';
  int id = 1;
  ss[0] = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i-1])
      ss[id++] = s[i];
  }
  for (int i = 0; i < id; i++)
    s[i] = ss[i];
  memset(ok, 0, sizeof ok);
  for (int i = 0; i < id; i++) {
    if (!ok[s[i]])
      dp[1][i] = 1;
    ok[s[i]] = 1;
  }
  for (int i = 2; i <= n; i++) {
    long long now = 0;
    for (int j = 0; j < 26; j++)
      sum[j] = 0;
    for (int j = 0; j < id; j++) {
      now += dp[i-1][j];
      if (now >= mod)
        now -= mod;
      dp[i][j] += now - sum[s[j]];
      if (dp[i][j] >= mod)
        dp[i][j] -= mod;
      if (dp[i][j] < 0)
        dp[i][j] += mod;
      sum[s[j]] = now;
    }
  }
  long long ans = 0;
  for (int i = 0; i < id; i++) {
    ans += dp[n][i];
    if (ans >= mod)
      ans -= mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%d\n", (int)ans);
  return 0;
}