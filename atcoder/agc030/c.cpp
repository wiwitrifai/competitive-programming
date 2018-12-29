#include <bits/stdc++.h>

using namespace std;

int a[505][505];

int main() {
  int k;
  scanf("%d", &k);
  if (k == 1) {
    puts("1\n1");
    return 0;
  }
  int n = (k+3)/4 * 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = (i+j) % n;
      if ((i & 1) && a[i][j]+n < k)
        a[i][j] += n;
    }
  }
  assert(n <= 500);
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ++a[i][j];
      printf("%d%c", a[i][j], j == n-1 ? '\n' : ' ' );
    }
  }

  return 0;
}