#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m, a, b;
  scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
  long long r = n % m;
  if (r == 0) {
    puts("0");
    return 0;
  }
  long long ans = min((m-r) * a, r * b);
  printf("%lld\n", ans);
  return 0;
}