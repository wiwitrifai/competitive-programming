#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;
  scanf("%lld %lld", &a, &b);
  if (a == 0 || b == 0) {
    puts("1");
    return 0;
  }
  long long n = a + b;
  long long ans = 0;
  for (long long g, p = 1, q; p <= n; p = q) {
    g = (n + p - 1) / p;
    if (g == 1) {
      ans += n+1 - p;
      break;
    }
    q = (n + g - 2) / (g-1);
    assert(p < q);
    assert(((n + q - 2) / (q-1)) == g);
    long long la = (a + g - 1) / g, lb = (b + g - 1) / g;
    long long ra = a / (g-1), rb = b / (g-1);
    if (la > ra || lb > rb) continue;
    assert(la <= ra && lb <= rb);
    ans += max(0LL,  min(q, ra + rb + 1) - max(p, la+lb));
  }
  printf("%lld\n", ans);
  return 0;
}
