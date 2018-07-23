#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

long long fib[N];

int main() {
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < N; ++i)
    fib[i] = (fib[i-1] + fib[i-2]) % mod;
  int t;
  scanf("%d", &t);
  while (t--) {
    int m, n;
    scanf("%d %d", &m, &n);
    long long a = 0, b = 0;
    for (int i = 0; i < m; ++i) {
      int x;
      scanf("%d", &x);
      a += x;
    }
    for (int i = 0; i < m; ++i) {
      int x;
      scanf("%d", &x);
      b += x;
    }
    a %= mod;
    b %= mod;
    long long ans = 0;
    if (n == 1)
      ans = a;
    else
      ans = (a * fib[n-2] + b * fib[n-1]) % mod;
    ans = ans * m % mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}