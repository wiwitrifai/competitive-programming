#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 50;
  printf("%d\n", t);
  srand(time(NULL));
  while (t--) {
    int n = 50, r = rand();
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
      printf("%d %d\n", rand(), rand());
  }
  return 0;
}