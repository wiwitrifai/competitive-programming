#include <bits/stdc++.h>

using namespace std;

long long sqrt_floor(long long x) {
  if (x <= 0) return 0;
  long long xx = sqrt(x);
  while ((xx + 1) * (xx + 1) <= x) xx++;
  while (xx * xx > x) xx--;
  return xx;
}

long long sqrt_ceil(long long x) {
  if (x <= 0) return 0;
  long long xx = sqrt(x);
  while (xx * xx >= x) xx--;
  while (xx * xx < x) xx++;
  return xx;
}

int main() {
  long long r, d;
  cin >> r >> d;
  long long ans = 2 * (r + d);
  if (r-d > 0)
    ans -= 2 * (r-d-1);
  else
    ans++;
  // cerr << ans << endl;
  long long rpd = r + d, rmd = r-d;
  rpd *= rpd;
  rmd *= rmd;
  for (long long k = 1; k <= r + d; k++) {
    long long up = sqrt_floor(rpd - k * k);
    long long down = k > r-d ? 0 : sqrt_ceil(rmd - k * k);
    // cerr << down << " " << up << endl;
    if (down == 0)
      ans += 4 * up + 2;
    else if (down > 0) {
      down--;
      up -= down;
      ans += 4 * up;
    }
  } 
  cout << ans << endl;
  return 0;
}