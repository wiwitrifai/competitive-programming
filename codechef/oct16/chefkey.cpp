#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    int ans = 0;
    for (int i = 1; i * i <= k; i++) if ((k % i) == 0) {
      ans += i <= r && (k/i) <= c;
      if (i * i != k) {
        ans += i <= c && (k/i) <= r;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}