#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N];
int val[N][N];
int dp[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), val[i][i] = dp[i][i] = a[i];
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      int r = i+len-1;
      val[i][r] = val[i][r-1] ^ val[i+1][r];
      dp[i][r] = max(val[i][r], max(dp[i][r-1], dp[i+1][r]));
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    printf("%d\n", dp[l][r]);
  }
  return 0;
}