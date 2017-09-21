#include <bits/stdc++.h>

using namespace std;

const int N = 202;
const long long inf = 1e18;

long long dp[N][N][2 * N];
char s[N][N];

void add(long long &le, long long ri) {
  le += ri;
  if (le > inf)
    le = inf;
}
int val(char c) {
  return c == '(' ? 1 : -1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  if (s[0][0] == ')') {
    puts("0");
    return 0;
  }
  dp[0][0][1]  = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2 * N; k++) {
        if (dp[i][j][k] == 0) continue;
        if (i < n && k + val(s[i+1][j]) >= 0)
          add(dp[i+1][j][k + val(s[i+1][j])], dp[i][j][k]);
        if (j < m && k + val(s[i][j+1]) >= 0)
          add(dp[i][j+1][k + val(s[i][j+1])], dp[i][j][k]);
      }
    }
  }
  printf("%lld\n", dp[n-1][m-1][0]);
  int k;
  scanf("%d", &k);
  printf("%d\n", k);
  return 0;
}