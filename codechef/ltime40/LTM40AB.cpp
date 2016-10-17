#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    long long ans = 0;
    for (int i = a; i <= b; i++) {
      int now = max(0, d - max(c-1, i));
      ans += now;
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}