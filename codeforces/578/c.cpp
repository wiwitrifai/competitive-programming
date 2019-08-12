#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  long long n, m;
  int q;
  scanf("%lld %lld %d", &n, &m, &q);
  long long d = gcd(n, m);
  long long x = n / d, y = m / d;
  while (q--) {
    int a, p;
    long long b, q;
    scanf("%d %lld %d %lld", &a, &b, &p, &q);
    --b, --q;
    if (a == 1)
      b /= x;
    else
      b /= y;
    if (p == 1)
      q /= x;
    else
      q /= y;
    puts(b == q ? "YES" : "NO");
  }
  return 0;
}
