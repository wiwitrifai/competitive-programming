#include <bits/stdc++.h>

using namespace std;

const int N = 555;

double C[N];
double p[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%lf", p+i);
  for (int i = 0; i < n; ++i) {
    C[i] = (double)k / n;
    for (int j = 1; j < k; ++j)
      C[i] *= (double)(i + 1 - j) / (n - j);
  }
  for (int i = 0; i < n; ++i) {
    if (i)
      printf(" ");
    double ans = 0;
    for (int j = 0; j + k <= n; ++j) {
      int id = (i + n - j) % n;
      ans += p[id] * C[n-j-1];
    }
    printf("%.9lf", ans);
  }
  printf("\n");
  return 0;
}
