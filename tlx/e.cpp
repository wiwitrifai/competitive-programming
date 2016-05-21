#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
long long p, q;

int main() {
  cin >> n >> a >> p;
  cin >> m >> b >> q;
  long long bm = b*m;
  long long an = a*n;
  long double add = (long double)(180 - 180*(m-2)/m);
  long double ans = (q-1)*add;
  q = (q-1) * b;
  p = (n-p+1);
  if(p == n)
    p = 0;
  ans += 360.0*p/n;
  p *= a;
  int cnt = 0;
  while(true) {
    while(p+a <= q) {
      p += an;
      ans += 360;
    }
    while(q+bm<=p) {
      q += bm;
      ans += 360;
    }
    if(q < p+a && p < q+b)
      break;
    if(++cnt > 1e7) {
      puts("-1");
      return 0;
    }
  }
  // cout << cnt << endl;
  cout << fixed << setprecision(15) << ans << endl;
  // cout << addd << endl;
  return 0;
}