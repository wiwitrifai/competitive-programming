#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = n;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      ans = min(ans, n-x);
    }
    printf("%d\n", ans);
  }
  return 0;
}