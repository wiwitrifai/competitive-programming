#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 5, mod = 1e9 + 7;

vector<string> valid = {"NW", "NE", "SE", "SW"};
long long dp[N];
char s[N];

int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%s", s);
  int n = strlen(s);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    dp[i+1] = dp[i];
    bool ok = 0;
    if (i > 0)
    for (string v : valid) {
      if (s[i-1] == v[0] && s[i] == v[1])
        ok = 1;
    }
    if (ok) {
      dp[i+1] += dp[i-1];
      if (dp[i+1] >= mod) dp[i+1] -= mod;
    }
  }
  printf("%lld\n", dp[n]);
  return 0;
}