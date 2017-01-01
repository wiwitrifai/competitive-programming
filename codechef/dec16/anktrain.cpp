#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int r = n % 8;
    if (r == 0)
      printf("%dSL\n", n - 1);
    else if (r == 7)
      printf("%dSU\n", n + 1);
    else if (r == 1)
      printf("%dLB\n", n + 3);
    else if (r == 4)
      printf("%dLB\n", n - 3);
    else if (r == 2)
      printf("%dMB\n", n + 3);
    else if (r == 5)
      printf("%dMB\n", n - 3);
    else if (r == 3)
      printf("%dUB\n", n + 3);
    else
      printf("%dUB\n", n - 3);
  }

  return 0;
}