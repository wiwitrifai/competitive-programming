#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    bool late = 0;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      if (a) {
        if (late)
          ans += 100;
      }
      else {
        late = 1;
        ans += 1100;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}