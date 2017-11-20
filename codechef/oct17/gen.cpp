#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {
  srand(time(0));
  int t = 1;
  printf("%d\n", t);
  while (t--) {
    int n = 1e6, q = 1e5;
    printf("%d %d\n", n, q);
    for (int i = 0; i < n; i++)
      printf("%d%c", i, (i == n-1) ? '\n' : ' ');
    for (int i = 0; i < q; i++) {
      int t = rand() % 100;
      if (t < 100) {
        printf("+ %d %d\n", (1LL * rand() * rand() % n) + 1, (rand() % 10000) + 1);
      }
      else {
        int le = (1LL * rand() * rand() % inf) + 1, ri = (1LL * rand() * rand() % inf) + 1;
        if (le > ri)
          swap(le, ri);
        printf("? %d %d %d\n", (1LL * rand() * rand() % n) + 1, le, ri);
      }
    }
  }
  return 0;
}