#include <bits/stdc++.h>

using namespace std;

const int N = 1002;
int dp[2][N * N];
int n, k;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  scanf("%d %d", &n, &k);
  vector< int > va[2];
  for (int i = 0; i < k; i++) {
    int a;
    scanf("%d", &a);
    a -= n;
    if (a == 0) {
      puts("1");
      return 0;
    }
    if (a < 0)
      va[0].push_back(-a);
    else
      va[1].push_back(a);
  }
  if (va[0].empty() || va[1].empty()) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < 2; i++) {
    sort(va[i].begin(), va[i].end());
    va[i].erase(unique(va[i].begin(), va[i].end()), va[i].end());
  }
  int up = N;
  for (int a : va[0]) for (int b : va[1]) {
    int d = gcd(a, b);
    up = min(up, (a+b)/d);
  }
  int ans = up;
  up *= min(va[0].back(), va[1].back());
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= up; j++)
      dp[i][j] = up;
    dp[i][0] = 0;
    for (int j = 0; j < up; j++) {
      for (int a : va[i])
        if (a + j <= up)
          dp[i][a+j] = min(dp[i][a+j], dp[i][j] + 1);
        else
          break;
    }
  }
  for (int i = 1; i <= up; i++) {
    ans = min(ans, dp[0][i] + dp[1][i]);
  }
  printf("%d\n", ans);
  return 0;
}