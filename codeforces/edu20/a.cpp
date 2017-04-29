#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int x[N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (x[i][j]) continue;
      if (k == 0) continue;
      if (i != j && k < 2) continue;
      x[i][j] = 1;
      k--;
      if (i != j) {
        x[j][i] = 1;
        k--;
      }
    }
  }
  if (k) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", x[i][j]);
    printf("\n");
  }
  return 0;
}