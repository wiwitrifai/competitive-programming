#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    scanf("%d %d", &x, &y);
    while (x > 0 && y > 0 && x != y) {
      if (x > y) swap(x, y);
      int k = y/x;
      if (x * k == y)
        --k;
      y -= x * k;
    }
    printf("%d\n", x + y);
  }
  return 0;
}