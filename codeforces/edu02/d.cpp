#include <bits/stdc++.h>

using namespace std;
const long double pi = acos(-1);
int main() {
  long long x, y, r, a, b, c;
  cin >> x >> y >> r >> a >> b >> c;
  if(r > c) {
    swap(r, c);
    swap(x, a);
    swap(y, b);
  }
  cout << fixed << setprecision(20);
  long long dx = x-a, dy = y-b;
  long long dd = dx * dx + dy * dy;
  long double d = sqrt(dd);
  if(dd >= (r + c) * (r + c)) {
    cout << 0.0 << endl;
    return 0;
  }
  if(d + r <= c) {
    long double ans = pi * r * r;
    cout << ans << endl;
    return 0;
  }
  long double p = (r * r - c * c + dd) / (2 * d);
  long double q = d - p;
  if(r * r + c * c < dd) {
    long double angle1 = acos(p/r), angle2 = acos(q/c);
    long double ans = angle1 * r * r - sin(angle1) * r * p  + angle2 * c * c - sin(angle2) * c * q;
    cout << ans << endl;
  }
  else {
    p = -p;
    q = d + p;
    long double angle1 = pi-acos(p/r), angle2 = acos(q/c);
    long double ans = angle1 * r * r + sin(angle1) * r * p  + angle2 * c * c - sin(angle2) * c * q;
    cout << ans << endl;
  }

  return 0;
}

// - x ^ 2 + r2 = -(d+x)2 + R2
// r^2 - R^2 + d^2 = 2xd
// x = 