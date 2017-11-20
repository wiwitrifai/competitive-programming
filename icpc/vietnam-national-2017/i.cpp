#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    for (int i = a; i <= b; ++i) {
      int now = i;
      int mul = 1;
      int len = 0;
      while (now) {
        len++;
        now /= 10;
      }
      for (int j = 0; j < len-1; j++) {
        mul *= 10;
      }
      now = i;
      for (int j = 0; j < len; j++) {
        now = (now % 10) * mul + (now/ 10);
        if (i == now) break;
        if (i < now && now <= b)
          ans++;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}