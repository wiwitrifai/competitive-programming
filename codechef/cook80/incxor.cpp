#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
long long dp[40][40][40];
int a[10];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    memset(dp, 0, sizeof dp);
    dp[31][0][0] = 1;
    for (int i = 30; i >= 0; i--) {
      int row = 0;
      for (int j = 0; j < n; j++)
        if (a[j] & (1<<i))
          row |= 1<<j;
      for (int mask = 0; mask < (1<<(n-1)); mask++) {
        for (int b = 0; b < (1<<(n-1)); b++) { 
          long long cur = dp[i+1][mask][b];
          if (cur == 0) continue;
          for (int bnext = 0; bnext < (1<<n); bnext++) {
            bool ok = 1;
            for (int j = 0; j < n-1; j++)
              if (!(b & (1<<j)))
                if ((bnext & (1<<j)) > 0 && (bnext & (1<<(j+1))) == 0) 
                  ok = 0;
            if (!ok) continue;
            int val = bnext ^ row;
            for (int j = 0; j < n-1; j++)
              if (!(mask & (1<<j)))
                if ((val & (1<<j)) > 0 && (val & (1<<(j+1))) == 0) 
                  ok = 0;
            if (!ok) continue;
            int nmask = mask, nb = b;
            for (int j = 0; j < n-1; j++)
              if (!(b & (1<<j)))
                if ((bnext & (1<<j)) == 0 && (bnext & (1<<(j+1))) > 0)
                  nb |= 1<<j; 
            for (int j = 0; j < n-1; j++)
              if (!(mask & (1<<j)))
                if ((val & (1<<j)) == 0 && (val & (1<<(j+1))) > 0)
                  nmask |= 1<<j;
            (dp[i][nmask][nb] += cur) %= mod;
          } 
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < (1<<(n-1)); i++)
      for (int j = 0; j < (1<<(n-1)); j++)
        (ans += dp[0][i][j]) %= mod;
    cout << ans << endl;
  }
  return 0;
}