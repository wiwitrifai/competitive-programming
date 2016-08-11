#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    long long now = 9;
    long long ans = 0;
    while(now <= r) {
      ans += (now >= l);
      now = (now * 10 + 9);
    }
    printf("%lld\n", ans * (r-l + 1));
  }
  return 0;
}