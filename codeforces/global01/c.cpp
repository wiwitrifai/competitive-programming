#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a & (a+1)) {
      int x = 1;
      while (x <= a) x <<= 1;
      --x;
      printf("%d\n", x);
    }
    else {
      int ans = 1;
      for (int i = 2; 1LL * i * i <= a; ++i) {
        if (a % i) continue;
        ans = max(ans, i);
        ans = max(ans, a/i);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}