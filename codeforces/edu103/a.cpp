#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long z = k;
  if (k < n) {
    z = 1LL * ((n + k - 1) / k) * k;
  }
  printf("%lld\n", (z + n - 1) / n);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
