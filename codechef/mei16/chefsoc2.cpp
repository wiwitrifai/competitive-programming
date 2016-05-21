#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;

int n, m, a[N], dp[N][2];
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int s;
    scanf("%d%d%d", &n, &m, &s);
    memset(dp, 0, sizeof dp);
    dp[s-1][0] = 1;
    int now = 0;
    while(m--) {
      int bef = now;
      now ^= 1;
      int a;
      scanf("%d", &a);
      for(int i = 0; i<n; i++) {
        dp[i][now] = ((i-a >= 0 ? dp[i-a][bef] : 0) + (i+a <n ? dp[i+a][bef] : 0)) % mod;
      }
    }
    for(int i = 0; i<n; i++)
      printf("%d ", dp[i][now]);
    printf("\n");
  }
  return 0;
}