// TLE
// Random solution

#include <bits/stdc++.h>

using namespace std;

const int N = 2048, inf = 1e9;

char s[N], t[N];
int n, dp[N][N];

void upd(int & var, int val) {
  if (var > val)
    var = val;
}

int main() {
  srand(time(0));
  scanf("%s", s);
  n = strlen(s);
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') ++cnt0;
    else ++cnt1;
  }
  if (cnt0 < cnt1) {
    for (int i = 0; i < n; ++i)
      printf("0");
    printf("\n");
    return 0;
  }
  else if (cnt0 > cnt1) {
    for (int i = 0; i < n; ++i)
      printf("1");
    printf("\n");
    return 0;
  }
  t[n]= 0;
  do {
    for (int i = 0; i < n; ++i) {
      t[i] = (s[i] == '0') ? '1' : '0';
    }
    int sama = rand() % n/2;
    while (sama-- > 0) {
      int x = rand() % n;
      t[x] = (t[x] == '0') ? '1' : '0';
    }
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        upd(dp[i+1][j], dp[i][j]+1); 
        upd(dp[i][j+1], dp[i][j]+1);
        upd(dp[i+1][j+1], dp[i][j] + (s[i] != t[j]));
      }
      upd(dp[i+1][n], dp[i][n]+1);
    }
    for (int i = 0; i < n; ++i)
      upd(dp[n][i+1], dp[n][i]+1);
    if (dp[n][n] > n/2) {
      printf("%s\n", t);
      return 0;
    }
  } while (1);
  return 0;
}