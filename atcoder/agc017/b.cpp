#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  n--;
  b -= a;
  d -= c;
  for (int i = 0; i <= n; i++) {
    long long cur = c * (n - 2 * i);
    long long low = cur - d * i, up = cur + d * (n - i);
    if (low <= b && b <= up) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}