/**
 *  ACM ICPC Regional Jakarta 2016 - E : Guessing Game
 */

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

// (a, b)
typedef pair<long long, long long> point;

long long area(vector<point> vp) {
  long long res = 0;
  for (int i = 0; i < vp.size(); i++) {
    point a = vp[i], b = vp[(i+1) % vp.size()];
    res += a.first * b.second - a.second * b.first;
  }
  res = abs(res);
  return res;
}

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    long long al, ar, bl, br, cl, cr, n;
    scanf("%lld %lld %lld %lld %lld %lld %lld", &al, &ar, &bl, &br, &cl, &cr, &n);
    ar -= al;
    br -= bl;
    cr -= cl;
    n -= al + bl + cl;
    long long ans = 0;
    if (0 > n || ar + br + cr < n)
      ans = 0;
    else {
      vector<point> vp;
      // check (a, 0)
      if (n - ar >= 0 && n - ar <= cr)
        vp.emplace_back(ar, 0);
 
      // c = cr
      if (n - cr <= 0)
        vp.emplace_back(0, 0);
      else {
        if (n-cr <= ar)
          vp.emplace_back(n-cr, 0);
        else
          vp.emplace_back(ar, n-cr-ar);
        if (n-cr <= br)
          vp.emplace_back(0, n-cr);
        else
          vp.emplace_back(n-cr-br, br);
      }

      // check (0, br)
      if (n - br >= 0 && n - br <= cr)
        vp.emplace_back(0, br);

      // c = 0 
      if (n >= ar + br)
        vp.emplace_back(ar, br);
      else {
        if (n <= br)
          vp.emplace_back(0, n);
        else
          vp.emplace_back(n-br, br);

        if (n <= ar)
          vp.emplace_back(n, 0);
        else
          vp.emplace_back(ar, n-ar);
      } 
      vp.erase(unique(vp.begin(), vp.end()), vp.end());
      long long a2 = area(vp);
      long long b2 = 0;
      for (int i = 0; i < vp.size(); i++) {
        point nx = vp[(i+1) % vp.size()], cur = vp[i];
        b2 += gcd(abs(nx.first-cur.first), abs(nx.second-cur.second));
      }
      ans = (a2-b2 + 2)/2 + b2;
    }
    ans %= mod;
    if (ans < 0)
      ans += mod;
    printf("Case #%d: %lld\n", tc, ans);

  }
  return 0;
} 