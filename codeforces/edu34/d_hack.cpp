#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 2e5;
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", (i < n/2 ? 1 : (int)1e9), " \n"[i == n-1]);
  }
  return 0;
}