#include <bits/stdc++.h>

using namespace std;
const long double pi = acos(-1);
long double a, b, p, q, x, y;

int main() {
  // freopen("ellipse.in", "r", stdin);
  // freopen("ellipse.out", "w", stdout);
  cin >> a >> b >> p >> q >> x >> y;
  x *= b; p *= b;
  y *= a; q *= a;
  long double r = a * b;
  long double len = ((-p)*(x-p) + (-q)*(y-q)) / sqrt((x-p)*(x-p) + (y-q)*(y-q));
  if(len < 0)
    len = -len;
  cout << fixed << setprecision(6);
  long double res = (r - len) / (r + len);
  cout << res << endl;

  if(len >= r)
    cout << 0 << endl;
  else {
    long double tem = sqrt(r*r - len*len) * len + r*r*asin(len/r) + pi * r * r / 2.0;
    long double sis = pi * r * r - tem;
    if(tem > sis)
      swap(tem, sis);
    cout << tem / sis << endl;  
  }
  return 0;
}