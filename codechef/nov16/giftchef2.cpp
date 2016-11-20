#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e5 + 6;
const int mod = 1e9 + 7;
 
char s[N], p[N];
int b[N];
long long dp[N];
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", s, p);
    int n = strlen(s), m = strlen(p);
    int z = -1;
    b[0] = -1;
    for (int i = 1; i < m; i++) {
      while (z != -1 && p[z] != p[i]) z = b[z];
      z++;
      b[i] = z;
    }
    b[m] = z+1;
    z = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      while (z != -1 && s[i] != p[z]) z = b[z];
      z++;
      dp[i+1] = dp[i];
      if (z == m) {
        dp[i+1] += (dp[i+1-m] + 1);
        dp[i+1] %= mod;
        z = b[z];
        while (z != -1 && s[i] != p[z]) z = b[z];
      }
    }
    dp[n] %= mod;
    if (dp[n] < 0)
      dp[n] += mod;
    printf("%lld\n", dp[n]);
  }
  return 0;
} 