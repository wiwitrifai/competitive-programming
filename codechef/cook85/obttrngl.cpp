#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    n -= 2;
    a = abs(a - b)-1;
    if (2 * a == n)
      puts("0");
    else
      printf("%d\n", min(a, n-a));
  }

  return 0;
}