#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;
int dp[N], tmp[N], lv[N];

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = n - 1; i >= 0; --i) {
    s[i] -= '0';
  }
  if (s[0])
    tmp[0] = 1;
  else
    dp[0] = tmp[0] = 1;
  int cur = 0, one = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i]) {
      cur = 0;
      ++one;
    } else {
      ++cur;
    }
    lv[i] = cur;
    dp[i] = (dp[i] + tmp[cur]) % mod;
    tmp[cur] = 0;
    if (s[i]) {
      tmp[0] = (tmp[0] + dp[i]) % mod;
      tmp[1] = (tmp[1] + dp[i]) % mod;
    } else {
      if (one) {
        tmp[0] = (tmp[0] + dp[i]) % mod;
        tmp[cur+1] = (tmp[cur+1] + dp[i]) % mod;
      } else {
        tmp[0] = (tmp[0] + dp[i]) % mod;
        if (s[i+1] == 0)
          dp[i+1] = (dp[i+1] + dp[i]) % mod;
      }
    }
  }
  long long ans = 0;
  int biggest = 0;
  int ada = 0;
  for (int i = n-1; i >= 0; --i) {
    if (s[i]) {
      ans = (ans + dp[i]) % mod;
      --one;
      ++ada;
    } else {
      if (ada) {
        if (one && lv[i] <= biggest) {
          ans = (ans + dp[i]) % mod;
        }
      } else {
        ans = (ans + dp[i]) % mod;
      }
      if (!ada)
        biggest = max(biggest, lv[i]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
