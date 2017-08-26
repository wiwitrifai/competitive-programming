#include <bits/stdc++.h>

using namespace std;

int main() {
  long long q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  long long ans = n * q * 4;
  ans = min(ans, n * h * 2);
  ans = min(ans, n * s);
  ans = min(ans, (n/2) * d + (n&1) * min(s, min(4 * q, 2 * h)));
  cout << ans << endl;
  return 0;
}