#include <bits/stdc++.h>

using namespace std;

long long get(long long r) {
  if (r < 10) return r;
  long long ans = 9, mul = 10;
  while (mul + 1 <= r) {
    for (int i = 1; i <= 9; ++i) {
      if (r < (mul+1) * i) break;
      long long v = r - (mul+1) * i;
      v /= 10;
      ans += min(v+1, mul/10);
    }
    mul *= 10;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    l--;
    printf("%lld\n", get(r) - get(l));
  }
  return 0;
}