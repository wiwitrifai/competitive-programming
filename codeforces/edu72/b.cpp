#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    int finish = -1, decr = -1;
    for (int i = 0; i < n; ++i) {
      int d, h;
      scanf("%d %d", &d, &h);
      if (i) {
        finish = max(finish, d);
        decr = max(decr, d - h);
      }
      else 
        finish = d, decr = d - h;
    }
    if (finish >= x) {
      puts("1");
      continue;
    }
    if (decr <= 0) {
      puts("-1");
      continue;
    }
    int ans = (x - finish + decr - 1) / decr + 1;
    printf("%d\n", ans);
  }
  return 0;
}
