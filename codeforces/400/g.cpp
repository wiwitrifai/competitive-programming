#include <bits/stdc++.h>

using namespace std;

long long dp[20][2][2];

int to[256];
long long solve(string s, int inc) {
  int n = s.size();
  long long ans = 0;
  for (int dm = 0; dm < 16; dm++) {
    for (int i = 0; i <= n; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          dp[i][j][k] = 0;
    dp[0][1][0] = 1;
    int pos = n-1-(dm/4), bit = 1<<(dm % 4);
    if (pos < 0) continue;
    for (int i = 0; i < n; i++) {
      for (int eq = 0; eq < 2; eq++) {
        for (int fill = 0; fill < 2; fill++) {
          long long val = dp[i][eq][fill];
          if (val == 0) continue;
          int dup = min(dm, eq ? to[s[i]] : dm);
          for (int d = 0; d <= dup; d++) {
            if ((pos == i) && ((d & bit) == 0)) continue;
            int teq = eq && (d == to[s[i]]), tfill = fill || (d == dm);
            dp[i+1][teq][tfill] += val;
          }
        } 
      }
    }
    for (int i = 0; i <= inc; i++)
      ans += dp[n][i][1];
  }
  return ans;
}

int main() {
  for (int i = 0; i <= 9; i++)
    to['0' + i] = i;
  for (int i = 'a'; i <= 'z'; i++)
    to[i] = i - 'a' + 10;
  int q;
  scanf("%d", &q);
  while (q--) {
    string l, r;
    cin >> l >> r;
    cout << solve(r, 1) -  solve(l, 0) << "\n";
  }
  return 0;
}