#include <bits/stdc++.h>

using namespace std;

long long C(int n) {
  return 1LL * n * (n - 1) / 2 + n;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans = C(n);
    n -= m;
    ++m;
    int k = n / m, r = n - k * m;
    ans -= 1LL * r * C(k+1) + 1LL * (m - r) * C(k);
    printf("%lld\n", ans);
  }
  return 0;
}
