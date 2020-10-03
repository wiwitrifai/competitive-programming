#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  while ((b - a) < n) {
    a *= 2;
    b *= 2;
  }
  for (int i = 0; i < n-1; ++i) {
    printf("%lld %lld\n", a, a+1);
    ++a;
  }
  printf("%lld %lld\n", a, b);
  return 0;
}
