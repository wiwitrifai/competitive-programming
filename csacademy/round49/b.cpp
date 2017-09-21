#include <bits/stdc++.h>

using namespace std;

int main() {
  int ans = 0;
  int n, c, x1, u, x2;
  scanf("%d %d %d %d %d", &n, &c, &x1, &u, &x2);
  for (int i = 0; i <= n; i++) {
    int up = i, cur = c, now = x1;
    for (int j = 0; j < n; j++) {
      if (up && cur >= u) {
        cur -= u;
        up--;
        now += x2;
      }
      cur += now;
    }
    ans = max(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}