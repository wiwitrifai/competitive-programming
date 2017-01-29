#include <bits/stdc++.h>

using namespace std;

long long calc(long long c, int k) {
  long long ret = 1;
  while (k) {
    if (k & 1)
      ret *= c;
    c *= c;
    k >>= 1;
  }
  return ret;
}

int main() {
  long long n;
  int k;
  scanf("%lld %d", &n, &k);
  if (k == 1) {
    long long r = 2;
    while (r < 1e7) {
      long long sum = r * (r + 1) / 2;
      if (n < sum)
        break;
      if ((n-sum) % r == 0) {
        long long a = (n-sum)/r;
        printf("%lld %lld\n", a+1, a+r);
        return 0;
      }
      r++;
    }
    puts("-1");
    return 0;
  }
  long long l = 1, r = 1, sum = 0;
  bool found = 0;
  while (r < 2e7) {
    long long now = calc(r, k);
    if (now > n)
      break;
    sum += now;
    r++;
    while (l + 1 < r && sum > n) {
      sum -= calc(l++, k);
    }
    if (l + 1 < r && sum == n) {
      found = 1;
      break;
    }
  }
  if (found)
    printf("%lld %lld\n", l, r-1);
  else
    puts("-1");
  return 0;
}