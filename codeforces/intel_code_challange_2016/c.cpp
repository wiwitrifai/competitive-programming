#include <bits/stdc++.h>

using namespace std;

int  n, m, k;
long long g, kpk;
const long long inf = 1e15;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long euclid(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = euclid(b, a % b, x, y);
  long long xx = y, yy = x - (a/b) * y;
  x = xx, y = yy;
  return d;
}

long long x, y, mulx, muly;

long long get(long long a, long long b) {
  long long diff = b-a;
  if (abs(diff) % g)
    return inf;
  diff /= g;
  long long p = x * diff, q = y * diff;
  long long kk = p / mulx;
  p -= mulx * kk;
  q += muly * kk;
  long long ret = inf;
  // cerr << diff << "\t" << kk << " " <<  p << " " <<q << endl;
    // cerr << ((p) * n + a) << " " << ((q) * m - b) << endl;
  for (int i = -2; i <=2; i++) {
    // cerr <<a << " " << b << " " <<  p+mulx*i << " " << q-muly*i << endl;
    // cerr << ((p+mulx*i) * n + a) << " " << ((q-muly*i) * m + b) << " " << ((p+mulx*i) * n - a) << " " << ((q-muly*i) * m - b) << endl;
    ret = min(ret, abs(p+mulx*i) * n + a);
  }
  return ret;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  // cerr << n << m << k << endl;
  n *= 2;
  m *= 2;
  g = euclid(n, m, x, y);
  // cerr << x << " " << y << endl;
  // cerr << x * n + m * y << endl;
  // cerr << g << endl;
  mulx = m/g, muly = n/g;
  // cerr << mulx << " " << muly << endl;
  kpk = (n/g) * m;
  long long ma = min(min(inf, get(0, m/2)), min(get(n/2, 0), get(n/2, m/2)));

  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    long long ans = min(min(get(x, y), get(x, m - y)), min(get(n - x, y), get(n - x, m - y)));
    if (ans > ma)
      ans = -1;
    printf("%I64d\n", ans);
  }


  return 0;
}