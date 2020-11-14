#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long g, h;
  scanf("%lld %lld", &g, &h);
  long long a, b;
  a = 1, b = 1;
  if (g == 1) {
    printf("%lld %lld\n", 1LL, h);
    return;
  }
  while (true) {
    a *= h;
    b = b * h + h - 1;
    long long x = (a + g - 1) / g * g;
    if (x == g)
      x += g;
    if (x <= b) {
      a = x;
      b = x * h + g;
      break;
    }
  }
  printf("%lld %lld\n", a, b);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
