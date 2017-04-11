#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0, x, cur = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      if (x)
        cur++;
      else {
        if (cur)
          cur--;
      }
      ans = max(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}