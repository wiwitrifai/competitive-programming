#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

int dp[N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  dp[0] = 0;
  for (int i = 1; i < N; i++) {
    dp[i] = dp[i-1] + 1;
    for (int x = 1; x * x <= i; x++)
      dp[i] = min(dp[i], dp[i-x*x]+1);
  }
  for (int tc = 1; tc <= tt; tc++) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: %d\n", tc, dp[n]);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}