#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long d, k;
  scanf("%lld %lld", &d, &k);
  long long d2 = d * d, dk = d2 / (k * k);
  long long ans = -1, diff = 1e18;
  for (long long x = 0; x * x <= dk; ++x) {
    long long r = dk - x * x;
    long long y = sqrt(r);
    while ((y + 1) * (y + 1) <= r) ++y;
    while (y * y > r) --y;
    if (y * y + (x + 1) * (x + 1) <= dk) {
      continue;
    }
    if (abs(x-y) < diff) {
      diff = abs(x-y);
      ans = x + y;
    }
  }
  puts(ans & 1 ? "Ashish" : "Utkarsh");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
