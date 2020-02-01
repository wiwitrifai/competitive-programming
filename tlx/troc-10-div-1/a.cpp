#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int len = (a + b + c - 2);
  long long ans = 1LL * len * (len + 1) / 2 - 1LL * a * (a - 1) / 2 - 1LL * c * (c - 1) / 2 - 1LL * e * (e - 1) / 2;
  printf("%lld\n", ans);
  return 0;
}
