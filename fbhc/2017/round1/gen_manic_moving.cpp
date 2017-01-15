#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int t = 100;
  // scanf("%d", &t);
  printf("%d\n", t);
  while (t--) {
    int n = (rand() % 51) + 50;
    int m = 5000, k = 5000;
    printf("%d %d %d\n", n, m, k);
    for (int i = 0; i < m; i++) {
      int u = (rand() % n) + 1, v = (rand() % n) + 1, w = (rand() % 1000) + 1;
      printf("%d %d %d\n", u, v, w);
    }
    for (int i = 0; i < k; i++) {
      int u = (rand() % n) + 1, v = (rand() % n) + 1;
      printf("%d %d\n", u, v);
    }
  }

  return 0;
}