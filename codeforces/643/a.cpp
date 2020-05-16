#include <bits/stdc++.h>

using namespace std;

int calc(long long a) {
  int dmin = 9, dmax = 0;
  while (a) {
    int d = a % 10;
    a /= 10;
    dmin = min(dmin, d);
    dmax = max(dmax, d);
  }
  return dmin * dmax;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, k;
    scanf("%lld %lld", &a, &k);
    k--;
    while (k > 0) {
      int res = calc(a);
      if (res == 0)
        break;
      --k;
      a += res;
    }
    printf("%lld\n", a);
  }
  return 0;
}
