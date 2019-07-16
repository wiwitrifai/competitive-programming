#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if ((n & 1) == 0) {
    printf("%d %d\n", n/2, n/2);
    return 0;
  }
  int b = 0;
  for (int i = 2; i <= n; ++i) {
    if (n % i) continue;
    b = n / i;
    break;
  }
  printf("%d %d\n", b, n-b);
  return 0;
}