#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0, now = 0;
    while (n--) {
      int tm, d;
      scanf("%d %d", &tm, &d);
      int bon = max(0, k-now);
      now += tm;
      tm -= bon;
      if (tm <= 0)
        continue;
      ans += tm * d;
    }
    printf("%d\n", ans);
  }
  return 0;
}