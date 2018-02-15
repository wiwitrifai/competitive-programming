#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int g[N];
int sum[N][10];

int f(int n) {
  int r = 1;
  while (n) {
    int d = n % 10;
    n /= 10;
    if (d)
      r *= d;
  }
  return r;
}

int main() {
  for (int i = 1; i < 10; ++i)
    g[i] = i;
  for (int i = 10; i < N; ++i) {
    g[i] = g[f(i)];
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < 10; ++j)
      sum[i][j] = sum[i-1][j];
    sum[i][g[i]]++;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    printf("%d\n", sum[r][k] - sum[l-1][k]);
  }
  return 0;
}