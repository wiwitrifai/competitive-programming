#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      ans = max(a, ans);
    }    
    int c;
    scanf("%d %*d %*d", &c);
    printf("%lld\n", 1LL * (c-1) * ans);
  }
  return 0;
}