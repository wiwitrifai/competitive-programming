#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int n = (rand() % 50) + 1;
  printf("%d\n", n);
  for (int i = 0; i < 2 * n; i++) {
    if (i) printf(" ");
    printf("%d", (rand() % 1000) + 1);
  }
  printf("\n");
  return 0;
}