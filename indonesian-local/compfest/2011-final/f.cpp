#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long g = gcd(a, b);
    a /= g;
    b /= g;
    puts((a-b) % 4 == 0 ? "ya" : "tidak");
  }
  return 0;
}