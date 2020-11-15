// WA/Unfinished

#include <bits/stdc++.h>

using namespace std;

const long long M = (1LL << 40) - 1;

inline long long f(long long s) {
  return s = (s + (s >> 20) + 12345) & M;
}

inline long long g(long long s, int k) {
  while (k--)
    s = f(s);
  return s;
}

inline long long calc(long long s, long long k) {
  long long ret = 0;
  while (k--) {
    ret += s & 1;
    s = f(s);
  }
  return ret;
}

int main() {
  const long long s = 1611516670LL;
  long long a = s, b = f(s);
  int period = 1;
  while (a != b) {
    a = f(a);
    b = f(f(b));
    ++period;
  }
  b = f(a);
  period = 1;
  while (a != b) {
    b = f(b);
    ++period;
  }
  int start = 0;
  a = s, b = g(s, period);
  while (a != b) {
    a = f(a);
    b = f(b);
    ++start;
  }
  long long n;
  scanf("%lld", &n);
  if (n <= start) {
    printf("%lld\n", calc(s, n));
    return 0;
  }
  long long ans = calc(s, start);
  n -= start;
  long long cur = g(s, start);
  long long cycle = calc(cur, period);
  ans += (n / period) * cycle;
  n %= period;
  ans += calc(cur, n);
  printf("%lld\n", ans);
  return 0;
}