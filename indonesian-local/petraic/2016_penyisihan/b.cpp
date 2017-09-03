#include <bits/stdc++.h>

using namespace std;

int fib[1024];
bool dp[2][1000024];

int main() {
  for (int n =  1; n < 102; n++) {
    int a = 0, b = 0;
    for (int m = 2; m < 5000; m+=2) {
      fib[1] = fib[2] = 1;
      for (int i = 3; i <= n; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % m;
      memset(dp, false, sizeof dp);
      dp[0][0] = true;
      for (int i = 1; i <= n; i++) {
        int c = i & 1, d = c ^ 1;
        for (int j = 0; j < m * n; j++) {
          dp[c][j] = (dp[d][abs(j-fib[i])]) || (j + fib[i] < m * n && dp[d][j + fib[i]]);
        }
      }
      if (dp[n & 1][0])
        a++;
      else
        b++;
      // cerr << n << " " << m << " " << dp[0][n & 1] << endl;
    }
    cerr << n << " " << a << " " << b << endl;
  }
  

  return 0;
}