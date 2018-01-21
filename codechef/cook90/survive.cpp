#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, s;
    scanf("%d %d %d", &n, &k, &s);
    bool ok = 1;
    int now = 0;
    for (int i = 1; i <= s; ++i) {
      if (i % 7)
        now += n;
      if (now < k) {
        ok = 0;
        break;
      }
      now -= k;
    }
    int ans = (s * k + n - 1) / n;
    if (!ok)
      ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}