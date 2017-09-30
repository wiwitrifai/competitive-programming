#include <bits/stdc++.h>

using namespace std;

const int N = 55, mod = 1e9+ 7;

int dp[N][1 << 13];
char s[N];

void upd(int & le, int ri) {
  le += ri;
  if (le >= mod)
    le -= mod;
}

int main() {
  memset(dp, 0, sizeof dp);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%s %d %d", s, &n, &k);
    k += 'a';
    int m = strlen(s);
    int ma = 1 << (m+1);
    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
      for (int b = 0; b < ma; b++)
        dp[i+1][b] = 0;
      for (int b = 0; b < ma; b++) {
        if (dp[i][b] == 0) continue;
        for (char up = 'a'; up < k; up++) {
          for (char down = 'a'; down < k; down++) {
            int mask = 1;
            if (b & (1 << m))
              mask |= 1 << m;
            for (int j = 0; j < m; j++) if (b & (1 << j)) {
              if (j + 1 < m && ((up == s[j] && down == s[j+1]) || (down == s[j] && up == s[j+1])))
                mask |= 1 << (j+2);
              if ((up == s[j]) || (down == s[j]))
                mask |= 1 << (j+1);
            }
            upd(dp[i+1][mask], dp[i][b]);
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < ma; i++) {
      if (i & (1 << m))
        upd(ans, dp[n][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}