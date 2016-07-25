#include <bits/stdc++.h>

using namespace std;
const int N = 505;

bool dp[N][N][N];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i<n; i++) {
    int a;
    scanf("%d",&a);
    dp[i][0][0] = 1;
    for(int j = 0; j<=k; j++)
      for(int z = 0; z <=j; z++) if(dp[i][j][z]) {
        if(j + a <= k) {
          dp[i+1][j+a][z+a] = true;
          dp[i+1][j+a][z] = true;
        }
        dp[i+1][j][z] = true;
      }
  }
  int cnt = 0;
  for(int i = 0; i<=k; i++) {
    cnt += dp[n][k][i];
  }
  printf("%d\n", cnt);
  for(int i = 0; i<=k; i++)
  if(dp[n][k][i]) 
    printf("%d ", i);
  printf("\n");
  return 0;
}