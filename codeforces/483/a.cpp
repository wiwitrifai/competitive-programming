#include  <bits/stdc++.h>

using namespace std;
long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long p, q, b;
    scanf("%I64d %I64d %I64d", &p, &q, &b);
    long long g = gcd(p, q);
    if (q > 1 && g > 1) {
      q /= g;
      g = gcd(p, q);
    }
    b = gcd(q, b);
    while (b > 1) {
      while ((q % b) == 0) q /= b;
      b = gcd(b, q);
    }
    puts(q == 1 ? "Finite" : "Infinite");
  }
  return 0;
}