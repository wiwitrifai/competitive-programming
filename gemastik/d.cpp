#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int b, l;
    scanf("%d %d", &b, &l);
    int lo = 0, hi = (l + b);
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      bool ok = true;
      int need = (l + b + mid - 1), ada = 4 * mid;
      int ujung = min(l, mid * 2);
      need -= ujung;
      ada -= ujung;
      need += l - ujung;
      if (ada >= need)
        hi = mid;
      else
        lo = mid + 1;
    }
    printf("%d\n", lo);
  }

  return 0;
}