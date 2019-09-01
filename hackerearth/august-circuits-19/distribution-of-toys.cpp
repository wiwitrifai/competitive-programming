#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int a = 1; a < n; ++a) {
      for (int b = 1; a + b < n; ++b) {
        int c = n - a - b;
        int m = max(a, max(b, c));
        int cnt = (m == a) + (m == b) + (m == c);
        ans += (cnt == 1);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
