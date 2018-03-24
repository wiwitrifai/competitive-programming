#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 16;

bool dp[40][N];
char s[40];

int main() {
  scanf("%s", s);
  int mask = 0;
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1')
      mask |= 1 << i;
  }
  dp[0][mask] = 1;
  int nmask = (1 << n)-1;
  for (int i = 0;; ++i) {
    if (dp[i][nmask]) {
      printf("%d\n", i);
      return 0;
    }
    int cur = (1 << (i+1))-1;
    for (int j = 0; j <= nmask; ++j) {
      if (!dp[i][j]) continue;
      for (int z = 0; z < n; ++z) {
        dp[i+1][(j^(cur<<z)) & nmask] = 1;
        dp[i+1][j] = 1;
      }
    }
  }
  return 0;
}