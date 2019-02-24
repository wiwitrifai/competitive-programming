#include <bits/stdc++.h>

using namespace std;

int main() {
  long long k;
  scanf("%lld", &k);
  for (long long x = 1999; x > 0; --x) {
    long long now = k + x;
    for (long long y = 1; y + x <= 2000; ++y) {
      if (now % y) continue;
      long long B = now / y + 1;
      if (B <= x * 1000000LL) {
        printf("%lld\n", x + y);
        for (int i = 0; i < y-1; ++i)
          printf("0 ");
        printf("-1 ");
        for (int i = 0; i < x; ++i) {
          long long cur = min(B, 1000000LL);
          printf("%lld ", cur);
          B -= cur;          
        }
        printf("\n");
        assert(B == 0);
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}