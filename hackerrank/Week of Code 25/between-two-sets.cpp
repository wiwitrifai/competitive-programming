#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}
long long lcm(long long a, long long b) {
  if (!a || !b)
    return a + b;
  return (a/gcd(a, b)) * b;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long l = 0, g = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    scanf("%lld", &a);
    l = lcm(l, a);
  }
  for (long long i = 0; i < m; i++) {
    long long b;
    scanf("%lld", &b);
    g = gcd(g, b);
  }
  if (g % l)
    puts("0");
  else {
    long long x = g/l;
    int ans = 0;
    for (long long i = 1; i *  i <= x; i++) if ((x % i) == 0) {
      ans += 1 + (i != x/i);
    }
    printf("%d\n", ans);
  }
  return 0;
}