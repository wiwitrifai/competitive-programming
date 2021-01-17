#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i < n; ++i) {
    if ((n % i) == 0) return false;
  }
  return true;
}

void solve() {
  int n;
  scanf("%d", &n);
  bool ans = (is_prime(n) && n < 7);
  puts(ans ? "YES" : "NO");
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
