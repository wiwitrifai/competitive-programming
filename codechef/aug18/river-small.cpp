#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int dp[N][2];
int p[N];

void rem(int v) {
  if (p[v] < 0) return;
  rem(p[v]);
  dp[p[v]][0] -= min(dp[v][0], dp[v][1]);
  dp[p[v]][1] -= dp[v][0];
}

void add(int v) {
  if (p[v] < 0) return;
  dp[p[v]][0] += min(dp[v][0], dp[v][1]);
  dp[p[v]][1] += dp[v][0];
  add(p[v]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    dp[0][1] = 0;
    p[0] = -1;
    for (int i = 1; i < n; ++i) {
      scanf("%d", p+i);
      --p[i];
      dp[i][0] = 1;
      dp[i][1] = 0;
      rem(p[i]);
      add(i);
      cerr << " add " << i << endl;
      for (int j = 0; j < n; ++j)
        cerr << j << " = " << dp[j][0] << " " << dp[j][1] << " = " << dp[j][1] - dp[j][0] << endl; 
      int ans = min(dp[0][0], dp[0][1]);
      if (ans == 1 && i+1 > 3) ++ans;
      ++ans;
      printf("%d%c", ans, i == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}