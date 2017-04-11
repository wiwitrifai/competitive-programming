#include <bits/stdc++.h>

using namespace std;

const int N = 21;

double dp[1 << N];
int a[N], n, sum;
double p[N];

int main() {
  scanf("%d", &n);
  sum = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), sum += a[i];
  for (int i = 0; i < n; i++)
    p[i] = (double)a[i]/sum;
  dp[(1<<n)-1] = 0;
  for (int mask = (1<<n)-2; mask >= 0; mask--) {
    double add = 1, dv = 1;
    for (int i = 0; i < n; i++)
      if (mask & (1<<i))
        dv -= p[i];
      else
        add += dp[mask | (1<<i)] * p[i];
    dp[mask] = add/dv;
  }
  printf("%.10lf\n", dp[0]);
  return 0;
}