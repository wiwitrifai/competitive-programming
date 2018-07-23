#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    n = 1LL * n * (n + 1) / 2;
    long long sum = n + m;
    if (sum & 1) {
      puts("No");
    }
    else {
      long long a = sum / 2;
      long long b = n - a;
      if (min(a, b) <= 0)
        puts("No");
      else
        puts(gcd(a, b) == 1 ? "Yes" : "No");
    }
  }
  return 0;
}