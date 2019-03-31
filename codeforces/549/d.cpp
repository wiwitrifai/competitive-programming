#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long dp[N][11];

int n;
char s[N];

long long get(int i, int d) {
  if (i < 0 || i >= n)
    return 0;
  if (dp[i][d] != -1)
    return dp[i][d];
  long long & ret = dp[i][d];
  ret = 1;
  if (i+1 >= n || s[i+1] >= d)
    return ret;
  d = (d + 10) % 11;
  int  cnt = 9 + d * (d + 1) / 2;
  cnt %= 11;
  ret += get(i+1, (cnt + s[i+1] + 1) % 11);
  return ret;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i)
    s[i] -= '0';
  memset(dp, -1, sizeof dp);
  long long ans =0;
  for (int i = 0; i < n; ++i) {
    if (s[i])
      ans += get(i, s[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
