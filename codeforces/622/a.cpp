#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = 0;
    for (int i = 0; i < (1 << 8); ++i) {
      int cnt[3];
      memset(cnt, 0, sizeof cnt);
      for (int j = 0; j < 8; ++j) {
        if (i & (1 << j)) {
          for (int k = 0; k < 3; ++k) {
            if (j & (1 << k))
              ++cnt[k];
          }
        }
      }
      bool ok = a >= cnt[0] && b >= cnt[1] && c >= cnt[2];
      if (ok) {
        ans = max(ans, __builtin_popcount(i)-1);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
