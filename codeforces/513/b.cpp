#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  while (n > 0) {
    int r = n % 10;
    n /= 10;
    if (r < 9 && n > 0) {
      ans += r + 10;
      --n;
    }
    else {
      ans += r;
    }
  }
  printf("%lld\n", ans);
  return 0;
}