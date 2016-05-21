#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long a, b, c, k;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
    long long ans = min(a, k-1) + min(b, k-1) + min(c, k-1) + 1;
    printf("%lld\n", ans);
  }
  return 0;
}