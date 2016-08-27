#include <bits/stdc++.h>

using namespace std;

int x[55][55];
int main() {
  int n;
  scanf("%d", &n);
  memset(x, 0, sizeof x);
  int m = n/2;
  if (m & 1) {
    for (int i = 1; i < n; i+=2)
      for (int j = 0; j < n; j++)
        x[i][j] = 1;
    for (int i = 0; i < n; i++)
      x[i][m] = 1;
  }
  else {
    for (int i = 0; i < n; i++) {
      if (i == m)
        continue;
      for (int j = 0; j <= m; j++)
        x[i][j] = 1;
    }
    for (int i = 0; i < n; i++) {
        x[i][n-i-1] = 0;
        x[i][i] = 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cnt += x[i][j];
  int a = 1, b = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (x[i][j]) {
        printf("%d ", a);
        a += 2;
      }
      else {
        printf("%d ", b);
        b += 2;
      }
    }
    printf("\n");
  }  
  return 0;
}