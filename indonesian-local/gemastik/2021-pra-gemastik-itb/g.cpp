#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  while (a > 0) {
    b %= a;
    swap(a, b);
  }
  return b;
}

long long lcm(long long a, long long b) {
  return (a / gcd(a, b)) * b;
}

pair<long long, long long> find(long long x, long long y, long long d) {
  long long r = (d - (x % d)) % d;
  return make_pair(lcm(x + r, y + r), r);
}

long long calc(long long x, long long y) {
  long long d = abs(y-x);
  pair<long long, long long> ans = {lcm(x, y), 0};
  for (long long f = 1; f * f <= d; ++f) {
    if (d % f) continue;
    ans = min(ans, find(x, y, f));
    long long o = d / f;
    if (o != f)
      ans = min(ans, find(x, y, o));
  }
  return ans.second;
}

long long calc2(long long x, long long y) {
  long long ans = 0, best = lcm(x, y);
  for (int i = 0; i <= 1000; ++i) {
    long long cur = lcm(x + i, y+i);
    if (cur < best) {
      best = cur;
      ans = i;
    }
  }
  return ans;
}

int main() {
  long long x, y;
  scanf("%lld %lld", &x, &y);
  printf("%lld\n", calc(x, y));
  return 0;
}
