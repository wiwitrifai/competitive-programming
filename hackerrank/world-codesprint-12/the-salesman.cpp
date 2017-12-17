#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int mi = 1000, ma = 1;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      mi = min(mi, x);
      ma = max(ma, x);
    }
    printf("%d\n", ma - mi);
  }
  return 0;
}