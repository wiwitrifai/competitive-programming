#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = (1LL << (n+1)) - 2;
    for (int i = 0; i < n/2; ++i) {
      int now = n/2 + i + 1;
      ans -= 1LL << now;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
