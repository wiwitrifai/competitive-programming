#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 4e4, q = n;
  printf("%d %d\n", n, q);
  for (int i = 0; i < n; ++i)
    printf("%d ", (rand() % n) + 1);
  for (int i = 0; i < q; ++i) {
    int l = rand() % n, r = rand() % n, k = rand() % n;
    ++l, ++r, ++k;
    // k = 300;
    if (l > r) swap(l, r);
    printf("%d %d %d\n", l, r, k);
  }
  return 0;
}