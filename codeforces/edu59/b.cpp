#include <bits/stdc++.h>

using namespace std;

int calc(int x) {
  if (x < 10)
    return x;
  int ret = 0;
  while (x > 0) {
    ret += x % 10;
    x /= 10;
  }
  return calc(ret);
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long k, x;
    scanf("%lld %lld", &k, &x);
    printf("%lld\n", (k-1) * 9 + x);
  }
  return 0;
}