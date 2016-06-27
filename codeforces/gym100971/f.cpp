#include <bits/stdc++.h>

using namespace std;
long long x[2], y[2], vx[2], vy[2];

int main() {
  for(int i = 0; i<2; i++)
    cin >> x[i] >> y[i];
  for(int i = 0; i<2; i++)
    cin >> vx[i] >> vy[i];
  long long a = x[1]- x[0], b = vx[1] - vx[0], c = y[1]-y[0], d = vy[1]-vy[0];
  long double t = 0;
  if(b || d) {
    t = -(long double)(a * b + c * d) / (long double)(b * b + d * d);
  }
  if(t < 0)
    t = 0;
  long double xx = (a + b * t);
  long double yy = (c + d * t);
  long double ans = sqrt(xx * xx + yy * yy);
  cout << fixed << setprecision(20) << ans << endl;

  return 0;
}