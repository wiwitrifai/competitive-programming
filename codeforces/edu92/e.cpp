#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

void solve() {
  int m, d, w;
  scanf("%d %d %d", &m, &d, &w);
  if (min(m, d) <= 1) {
    puts("0");
    return;
  }
  int g = gcd(d-1, w);
  int k = w / g;
  int lim = min(m, d);
  long long cnt = lim / k;
  long long sum = cnt * (cnt + 1) / 2;
  long long ans = cnt * lim - sum * k;
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
