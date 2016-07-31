#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const double eps = 1e-7;

double x[N][N];

int n, k, e[N];

int main() {
  
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    for(int j = 0;j<n; j++)
      scanf("%lf", x[i]+j);
  }
  scanf("%d", &k);
  for(int i = 0; i<k; i++) {
    scanf("%d", e+i);
    e[i]--;
  }
  int ans = 0;
  for(int i = 0; i<n; i++) {
    double now = 1;
    for(int j = 0; j<k; j++) {
      now *= x[i][e[j]];
    }
    if(now+eps >= 2)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}