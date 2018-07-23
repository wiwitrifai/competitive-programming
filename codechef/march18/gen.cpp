#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 1e5;
  srand(time(0));
  printf("%d\n", n);
  for (int i = 1; i < n; ++i) {
    int u = i+1, v = (rand() % i) + 1;
    printf("%d %d\n", u, v);
  }
  return 0;
}