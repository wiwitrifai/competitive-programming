#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  b = min(b, a+1);
  a = min(a, b+1);
  printf("%lld\n", a + b + 2 * c);
  return 0;
}
