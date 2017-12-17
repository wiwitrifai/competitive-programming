#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int n = 2e5, inf = 1e9;
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", (1LL * rand() * rand() % inf) + 1, i == n-1 ? '\n' : ' ');
  }
  for (int i = 1; i < n; ++i)
    printf("%d %d\n", i, i+1);

  return 0;
}