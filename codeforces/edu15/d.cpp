#include <bits/stdc++.h>


using namespace std;

long long k, a, b, d, t;

int main() {
  cin >> d >> k >> a >> b >> t;
  if(d <= k) {
    cout << a * d << endl;
    return 0;
  }
  long long ans = min(b * d, a*k + (d-k)*b);
  long long cnt = d/k, mobil = cnt*k;
  ans = min(ans, d * a + cnt * t);
  cnt--; mobil -= k;
  long long sisa = d - mobil;
  long long add = 0;
  if(sisa >= k) {
    add = 1;
    sisa -= k;
  }
  ans = min(ans, (mobil + add * k) * a + cnt * t + sisa * b);
  cout << ans << endl;

  return 0;
}