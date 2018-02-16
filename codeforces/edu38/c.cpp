#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
      puts("1 1");
      continue;
    }
    bool found = 0;
    for (int a = 1; 1LL * a * a <= x && !found; ++a) {
      if (x % a) continue;
      int b = x/a;
      int n = a + b;
      if (n & 1) continue;
      n /= 2;
      int k = b-n;
      if (k < 1 || k > n) continue;
      for (int m = max(n/k-2, 1); m <= min(n/k+2, n) && !found; ++m) {
        if (n/m == k) {
          printf("%d %d\n", n, m);
          found = 1;
        }
      }
    }
    if (!found) puts("-1");
  }
  return 0;
}