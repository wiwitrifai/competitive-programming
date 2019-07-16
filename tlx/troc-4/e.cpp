#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
};
ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << "," << p.y << ")";
}

point read() {
  int x, y;
  scanf("%d %d", &x, &y);
  return point(x, y);
}

const int ITER = 1000;
const LD eps = 1e-7;

point a, b, o;
int r;

LD dist(point a, point b) {
  LD dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx* dx + dy * dy);
}

LD calc(LD x) {
  LD dx = x - o.x;
  LD dy = sqrt((LD)r * r - dx * dx);
  point p = point(x, o.y+dy), q = point(x, o.y-dy); 
  // cerr << x << " : " << p << " " << q << endl;
  return min(dist(a, p) + dist(b, p), dist(a, q) + dist(b, q));
}


int main() {
  a = read(), b = read();
  o = read();
  scanf("%d", &r);
  long double le = o.x - r, ri = o.x + r;
  LD ans = calc(o.x);
  if (dist(a, o) <= r + eps && dist(b, o) <= r + eps)
    ans = dist(a, b);
  // cerr << ans << endl;
  for (int it = 0; it < ITER; ++it) {
    LD m1 = (le + le + ri) / 3, m2 = (le + ri + ri) / 3;
    LD r1 = calc(m1), r2 = calc(m2);
    ans = min(ans, min(r1, r2));
    if (r1 < r2)
      ri = m2;
    else
      le = m1;
    // cerr << le << " " << ri << " " << ans << endl;
  }
  printf("%.10lf\n", (double)ans);
  // cerr << calc(8) << " " << calc(10) << endl;
  return 0;
}