#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
const long double eps = 1e-9;

struct point {
  long long x, y;
  point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

struct line {
  long long a, b, c;
};

long double dist2(line l, point p) {
  long double up = (l.a * p.x + l.b * p.y + l.c);
  long double  down = l.a * l.a + l.b * l.b;
  return up / down * up; 
}

long long dist(point a, point b) {
  long long dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

void adjust(line &l, point p) {
  l.c = -l.a * p.x - l.b * p.y;
}

long long r[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int b, n, dx, dy, v;
    line l;
    point c;
    scanf("%d %d %d %d %d", &b, &n, &v, &dx, &dy);
    l.a = dy;
    l.b = -dx;
    long double d = sqrt((long double)dx * dx + (long double)dy * dy);
    long double ddx = dx/d, ddy = dy/d;
    for (int i = 0; i <= b; i++)
      scanf("%lld", r+i), r[i] *= r[i];
    scanf("%lld %lld", &c.x, &c.y);
    for (int i = 0; i < n; i++) {
      point p;
      scanf("%lld %lld", &p.x, &p.y);
      adjust(l, p);
      vector<pair<int, pair<double, double> > > ev;
      long double dd = dist2(l, c);
      long double mid = sqrt(dist(p, c) - (long double)dd);
      long double xx = c.x + ddx * mid - p.x, yy = c.y + ddy * mid - p.y;
      long double ddd = xx * xx + yy * yy - dist(p, c);
      if (ddd <= 0 || fabs(ddd) < eps)
        for (int j = b; j >= 0; j--) {
          if (dd >= r[j] || fabs(dd - r[j]) < eps) break;
          long double half = sqrt(r[j] - (long double)dd);
          ev.push_back(make_pair(j, make_pair(mid-half, mid+half)));
        }
      printf("%d\n", ev.size() * 2 - (ev.size() ? 1 : 0));
      for (int j = 0; j < ev.size(); j++) {
        if (j + 1 == ev.size())
          printf("%d %.12lf\n", ev[j].first, (ev[j].second.second-ev[j].second.first)/v);
        else
          printf("%d %.12lf\n", ev[j].first, (ev[j+1].second.first-ev[j].second.first)/v);
      }
      for (int j = (int)ev.size() - 2; j >= 0; j--) {
        printf("%d %.12lf\n", ev[j].first, (ev[j].second.second-ev[j+1].second.second)/v);
      }
    }
  }
  return 0;
}