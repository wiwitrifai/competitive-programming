/**
 * Coded by Luqman
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int REM = 25;

long long dp[10][10][REM]; // digit - X - rem
char s[N];

void add(long long& at, long long val) {
  at += val;
}

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int x = 0; x < 10; x++) {
    dp[0][x][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x < 10; x++) {
      if (s[i] == 'X') {
        for (int rem = 0; rem < REM; rem++) {
          if (i == 1 && x == 0 && n > 1) continue;
          add(dp[i][x][(rem * 10 + x) % REM], dp[i-1][x][rem]);
        }
      } else if (s[i] == '_') {
        for (int rem = 0; rem < REM; rem++) {
          for (int fill = 0; fill < 10; fill++) {
            if (i == 1 && fill == 0 && n > 1) continue;
            add(dp[i][x][(rem * 10 + fill) % REM], dp[i-1][x][rem]);
          }
        }
      } else {
        int c = s[i] - '0';
        if (i == 1 && c == 0 && n > 1) continue;
        for (int rem = 0; rem < REM; rem++) {
          add(dp[i][x][(rem * 10 + c) % REM], dp[i-1][x][rem]);  
        }
      }
    }
  }
  int has_x = 0;
  for (int i = 1; i <= n; i++) if (s[i] == 'X') has_x = 1;
  long long ans = 0;
  if (has_x) {
    for (int x = 0; x < 10; x++) {
      ans += dp[n][x][0];
    }
  } else {
    ans += dp[n][0][0];
  }
  cout << ans << endl;
  return 0;
}
