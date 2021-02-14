#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

void solve() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  vector<long long> a(n);
  long long d = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i < n; ++i) {
    d = gcd(d, abs(a[i] - a[0]));
  }
  puts((abs(k-a[0]) % d) == 0 ? "YES" : "NO");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
