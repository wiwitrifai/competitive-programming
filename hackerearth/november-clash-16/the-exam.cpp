#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x, n, l;
    scanf("%lld %lld %lld", &x, &l, &n);
    if (n == 0)
      puts("0");
    else {
      while (--n > 0 && l) l /= 2;
      printf("%lld\n", max(x-l, 0LL));
    }
  }
  return 0;
}