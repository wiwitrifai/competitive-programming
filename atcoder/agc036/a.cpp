#include <bits/stdc++.h>

using namespace std;

const long long upper = 1e9;

int main() {
  long long s;
  cin >> s;
  long long x = 1e9, a = 1, b = 1, y = 1;
  b = s / x;
  long long r = s - x * b;
  if (r > 0) {
    r -= x;
    ++b;
  }
  y = -r;
  assert(x *b - y * a == s);
  assert(a <= upper && b <= upper && y <= upper);
  printf("0 0 %lld %lld %lld %lld\n", x, y, a, b);
  return 0;
}
