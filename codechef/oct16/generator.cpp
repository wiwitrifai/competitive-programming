#include <bits/stdc++.h>

using namespace std;

const int A = 100, N = 20;


int main() {
  int t;
  scanf("%d", &t);
  printf("%d\n", t);
  while (t--) {
    int n = (rand() % N) + 1, m = (rand() % N) + 5;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
      printf("%d ", (rand() % A) + 1);
    }
    printf("\n");
    while (m--) {
      int ty, l, r, x;
      ty = (rand() % 3) + 1;
      l = (rand() % n) + 1;
      r = (rand() % n) + 1;
      if (l > r)
        swap(l, r);
      if (ty == 3)
        printf("%d %d %d\n", ty, l, r);
      else
        printf("%d %d %d %d\n", ty, l, r, (rand() % A) + 1); 
    }
  }
  return 0;
}