#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5, M = 55;
char s[N];
int dp[M][M * M];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &x, &n);
    int now = 0;
    s[n+1] = 0;
    s[x] = '2';
    int k = n < M ? n : -1;
    for (int i = n; i > 0; --i) {
      if (i == x) continue;
      if (now <= 0)
        s[i] = '0', now += i;
      else
        s[i] = '1', now -= i;
      if (now == 0 && i < M && k == -1)
        k = i-1;
    }
    int tot = 0;
    for (int i = 1; i <= k; ++i) {
      if (i == x) continue;
      tot += i;
    }
    if (tot & 1) {
      puts("impossible");
      continue;
    }
    tot >>= 1;
    for (int i = 0; i <= k; ++i)
      for (int j = 0; j <= tot; ++j)
        dp[i][j] = -1;
    dp[0][0]= 0;
    for (int i = 1; i <= k; ++i) {
      for (int j = 0; j <= tot; ++j) {
        if (dp[i-1][j] == -1) continue;
        dp[i][j] = 0;
        if (j + i <= tot && i != x)
          dp[i][j+i] = 1;
      }
    }
    if (dp[k][tot] == -1) {
      puts("impossible");
    }
    else {
      for (int i = k; i > 0; --i) {
        if (i == x) continue;
        s[i] = dp[i][tot] + '0';
        if (dp[i][tot])
          tot -= i;
      }
      printf("%s\n", s+1);
    }
  }
  return 0;
}