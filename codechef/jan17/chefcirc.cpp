#include <bits/stdc++.h>

using namespace std;

const int N = 555;
const double pi = acos(-1);

struct point
{
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {};
  double dist(point p) {
    double dx = x-p.x, dy = y-p.y;
    return hypot(dx, dy);
  }
};

///// Find two center of same size circle from its intersection and their radius
bool circle2PtsRad(point p1, point p2, double r, point *c, point *d) { // answer at *c
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if(det<0.0) return false;
  double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h;
  d->x = (p1.x + p2.x) * 0.5 - (p1.y-p2.y)*h;
  d->y = (p1.y + p2.y) * 0.5 - (p2.x-p1.x)*h;
  return true;
}

point p[N];
int n, m;

time_t startt;

const double eps = 1e-3, eps2 = 1e-6;
const int BOMB = 1990;
int ms;

bool check(double r) {
  point c, d;
  for (int i = 0; i < n; i++) {
    vector< pair<double, int > > ev;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (!circle2PtsRad(p[i], p[j], r, &d, &c)) continue;
      double ang1 = atan2(c.y-p[i].y, c.x-p[i].x),
      ang2 = atan2(d.y-p[i].y, d.x-p[i].x);
      if (ang2 < ang1) ang2 += 2 * pi;
      ev.push_back(make_pair(ang1, +1));
      ev.push_back(make_pair(ang2, -1));
      ev.push_back(make_pair(ang1 + 2 * pi, +1));
      ev.push_back(make_pair(ang2 + 2 * pi, -1));
    }
    sort(ev.begin(), ev.end());
    int cnt = 1;
    for (int j = 0; j < ev.size(); j++) {
      cnt += ev[j].second;
      if (cnt >= m)
        return true;
    }
    ms = (clock()-startt) * 1000/CLOCKS_PER_SEC;
    if (ms > BOMB)
      return false;
  }
  return false;
}

int main() {
  startt = clock();
  ms = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
  double l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      r = max(r, p[i].dist(p[j]));
    }
  }
  double tmp = 1e3 * sqrt(2);
  if (r > tmp)
    r = tmp;
  while (fabs(r-l) > eps) {
    double mid = (l + r)/2;
    if (check(mid))
      r = mid;
    else
      l = mid;
    ms = (clock()-startt) * 1000/CLOCKS_PER_SEC;
    if (ms > BOMB)
      break;
  }
  printf("%.6lf\n", l);
  cerr << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << endl;
  return 0;
}