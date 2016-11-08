#include <bits/stdc++.h>

using namespace std;

const int N = 12;

int a[N][N][N], dp[N][N][N];

int main() {
  freopen("commandos.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++) {
      int f, y, x, h;
      scanf("%d %d %d %d", &f, &y, &x, &h);
      a[f][y][x] += h;
    }
    for (int i = 10; i >= 0; i--) {
      for (int j = 1; j <= 10; j++) {
        for (int k = 1; k <= 10; k++) {
          dp[i][j][k] = a[i][j][k] + max(dp[i+1][j][k], max(dp[i][j-1][k], dp[i][j][k-1])); 
        }
      }
    }
    printf("%d\n", dp[0][10][10]); 
  }


  return 0;
}