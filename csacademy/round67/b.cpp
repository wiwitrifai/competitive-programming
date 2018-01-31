#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

long long dp[N][2];
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    dp[i][0] = 0;
    dp[i][1] = a[i];
    if (i) {
      dp[i][0] = max(dp[i-1][0], dp[i][0]);
      dp[i][1] = max(dp[i-1][1], dp[i][1]);
      dp[i][0] = max(dp[i][0], dp[i-1][1] + a[i]);
      dp[i][1] = max(dp[i][1], dp[i-1][0] + a[i]);
    }
  }
  cout << dp[n-1][0] << endl;
  return 0;
}