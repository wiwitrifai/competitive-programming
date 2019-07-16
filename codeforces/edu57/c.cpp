#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int d;
    scanf("%d", &d);
    d *= 2;
    int ans = -1;
    for (int n = 3; n <= 360; ++n) {
      if (360 % n) continue;
      int cur = 360 / n;
      if (d % cur) continue;
      int cnt = d / cur;
      if (cnt >= n-1) continue;
      ans = n;
      break;
    }
    printf("%d\n", ans);
  }
  return 0;
}