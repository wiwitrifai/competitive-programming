#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 +5;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a;
    scanf("%d", &n);
    int ans = 0, zero = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      if (a) {
        if (zero)
          ans = max(ans+1, zero);
      }
      else
        zero++;
    }
    printf("%d\n", ans);
  }

  return 0;
}