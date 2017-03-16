#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  printf("%d\n", t);
  while (t--) {
    int n, m;
    n = m = 300;
    int c = 1e6;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        printf("%d%c", c, j == m-1 ? '\n' : ' ');
    }
  }
  return 0;
}