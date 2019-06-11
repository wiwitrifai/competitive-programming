#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 998244353;

int dif[N];
int dp[N][N];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", dif+i);
  sort(dif, dif+n);
  int cnt = 0, last = dif[0];
  vector<int> prob;
  for (int i = 0; i < n; ++i) {
    if (last != dif[i]) {
      prob.push_back(cnt);
      cnt = 0;
      last = dif[i];
    }
    ++cnt;
  }
  prob.push_back(cnt);
  dp[0][0] = 1;
  for (int i = 0; i < (int)prob.size(); ++i) {
    for (int j = 0; j <= k; ++j) {
      if (dp[i][j] == 0) continue;
      int now = dp[i][j];
      add(dp[i+1][j], now);
      dp[i+1][j+1] = (dp[i+1][j+1] + 1LL * now * prob[i]) % mod;
    }
  }
  printf("%d\n", dp[prob.size()][k]);
  return 0;
}
