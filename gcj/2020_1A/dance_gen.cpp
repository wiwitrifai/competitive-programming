#include <bits/stdc++.h>

using namespace std;
const int N = 1e5, S = sqrt(N), X = 1e6;

void random_case(int n, int m) {
  printf("%d %d\n", n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      printf("%d ", (i == j) ? X : 1);
    printf("\n");
  }
}

int main() {
  int tt = 100;
  printf("%d\n", tt);
  for (int i = 0; i < 100; ++i) {
    int n = 1 + (rand() % S), m = (i < 10 ? N : 1000) / n;
    if (i & 1)
      n = 1, m = N;
    if (rand() & 1)
      swap(n, m);
    random_case(n, m);
  }
  return 0;
}
