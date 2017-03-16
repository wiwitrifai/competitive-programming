#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    int l, r;
    scanf("%d %d", &r, &l);
    if (l < r)
      swap(l, r);
    for (int i= 1; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      if (a > b)
        swap(a, b);
      l = min(b, l);
      r = max(a, r);
    }
    while (q--) {
      int a;
      scanf("%d", &a);
      puts((a <= r && a >= l) ? "YES" : "NOT SURE");
    }
  }
  return 0;
}