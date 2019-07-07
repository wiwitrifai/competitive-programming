#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, m, t;
  scanf("%d %d %d %d", &n, &k, &m, &t);
  while (t--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x) {
      if (y <= k)
        ++k;
      ++n;
    }
    else {
      if (y < k) {
        k -= y;
        n -= y;
      }
      else {
        n = y;
      }
    }
    printf("%d %d\n", n, k);
  }

  return 0;
}
