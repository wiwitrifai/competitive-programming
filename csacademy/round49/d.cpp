#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

long double dp[N][N];
long double p[N][N];

int main() {
  int t, a;
  scanf("%d %d", &t, &a);
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < a; j++) {
      int x;
      scanf("%d", &x);
      p[i][j] = (long double)x/100.0;
    }
  }
  for (int i = 0; i < a; i++)
    dp[0][i] = 0;
  for (int i = 0; i < t; i++) {
    long double mul = 1;
    long double sum = 0;
    for (int j = 0; j < a; j++) {
      sum += mul * (1 + (1.0-p[i][j]) * dp[i][(j+1) % a]);
      mul *= p[i][j]; 
    }
    dp[i+1][0] = sum/(1.0-mul);
    for (int j = a-1; j >= 0; j--) {
      int nx = (j + 1) % a;
      dp[i+1][j] = 1 + (1.0-p[i][j]) * dp[i][nx] + p[i][j] * dp[i+1][nx];
    }
  }
  printf("%.20lf\n", (double)dp[t][0]);
  return 0;
}