#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int g[N][N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  if (a > 1 && b > 1) {
    puts("NO");
    return 0;
  }
  if (n > 1 && n <= 3 && a == 1 && b == 1) {
    puts("NO");
    return 0;
  }
  puts("YES");
  memset(g, 0, sizeof g);
  if (a == 1 && b == 1) {
    for (int i = 1; i < n; ++i) {
      g[i][i-1] = g[i-1][i] = 1;
    }
  }
  else if (a > 1) {
    int k = n - a + 1;
    for (int i = 0; i < k; ++i)
      for (int j = 0; j < k; ++j)
        g[i][j] = (i != j);
  }
  else {
    int k = n - b + 1;
    for (int i = 0; i < k; ++i)
      for (int j = 0; j < k; ++j)
        g[i][j] = (i != j);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        g[i][j] ^= 1;
        if (i == j) g[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      printf("%d", g[i][j]);
    printf("\n");
  }
  return 0;
}