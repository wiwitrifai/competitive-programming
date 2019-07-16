#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int t = 2;
  printf("%d\n", t);
  while (t--) {
    int n = (1 << 17) - 1;
    cerr << n << endl;
    int q = 1e5;
    printf("%d %d\n", n, q);
    for (int i = 2; i <= n; ++i) {
      printf("%d %d\n", i/2, i);
    }
    for (int i = 0; i < q; ++i) {
      int v = (rand() % n) + 1, y = (rand()) + 1;
      printf("%d %d\n", v, y);
    }
  }
  return 0;
}
