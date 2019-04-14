#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, inf = 1e9 + 7;
bool leaf[N];
int op[N], p[N];
int dp[N][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", op+i);
  }
  fill(leaf, leaf+n, true);
  for (int i = 1; i < n; ++i) {
    scanf("%d", p+i);
    --p[i];
    leaf[p[i]] = 0;
  }
  for (int i = 0; i < n; ++i) {
    if (leaf[i]) {
      dp[i][0] = 1;
      dp[i][1] = 0;
    }
    else {
      dp[i][op[i]] = -inf;
      dp[i][op[i]^1] = 0;
    }
  }
  for (int i = n-1; i > 0; --i) {
    int v = p[i];
    int o = op[v];
    dp[v][o] = max(dp[v][o] + max(dp[i][0], dp[i][1]), dp[v][o^1] + dp[i][o]);
    dp[v][o^1] += dp[i][o^1];
  }
  printf("%d\n", dp[0][1] + 1);
  return 0;
}