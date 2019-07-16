#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

const int N = 3e5 + 5;

long long x[N], p[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", x+i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%lld", p+i);
  }
  long long y = x[0], r = 0;
  for (int i = 0; i + 1 < n; ++i) {
    r = gcd(r, x[i+1] - x[i]);
  }
  for (int i = 0; i < m; ++i) {
    if ((r % p[i]) == 0) {
      puts("YES");
      printf("%lld %d\n", y, i+1);
      return 0;
    }
  }
  puts("NO");
  return 0;
}
