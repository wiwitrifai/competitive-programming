#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-7;

struct point {
  long double x, y;
  point(long double x = 0, long double y = 0) : x(x), y(y) {} 
};

long double cross(point p, point q, point r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

point lineIntersectSeg(point p, point q, point A, point B) {
  long double a = B.y - A.y;
  long double b = A.x - B.x;
  long double c = B.x * A.y - A.x * B.y;
  long double u = fabs(a * p.x + b * p.y + c);
  long double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u)/(u + v), (p.y * v + q.y * u) / (u + v));
}

vector<point> cutPolygon(point a, point b, vector<point> Q) {
  vector<point> P;
  for (int i = 0; i < (int)Q.size(); i++) {
    long double left1 = cross(a, b, Q[i]), left2 = 0.0;
    if (i != (int)Q.size()-1) left2 = cross(a, b, Q[i+1]);
    if (left1 > -EPS) P.push_back(Q[i]);
    if (left1 * left2 < -EPS)
      P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
  }

  if (P.empty()) return P;
  if (fabs(P.back().x - P.front().x) > EPS || fabs(P.back().y - P.front().y) > EPS)
    P.push_back(P.front());
  return P;
}

long double area(vector<point> vp) {
  long double ret = 0;
  for (int i = 0; i + 1 < vp.size(); i++) {
    ret += vp[i].x * vp[i+1].y - vp[i].y * vp[i+1].x;
  } 
  return fabs(ret) / 2.0;
}

vector<point> dice = {point(0.5, 0.5), point(-0.5, 0.5), point(-0.5, -0.5), point(0.5, -0.5), point(0.5, 0.5)};
int val[4] = {6, 4, 1, 3};

int main() {
  vector<point> vp;
  for (int i = 0; i < 4; i++) {
    double x, y;
    scanf("%lf %lf", &x, &y);
    vp.push_back(point(x, y));
  }
  vp.push_back(vp.front());
  long double tot = 5 * 5 * 5 - 1 * 1 * 1;
  long double sum = 4 * 5 * 5 * 5;
  for (int i = 0; i < 4; i++) {
    vector<point> canSee = cutPolygon(dice[i], dice[i+1], vp);
    sum += 1.0 * val[i] * area(canSee) * 5;
  }
  double ans = sum/tot;
  printf("%.10lf\n", ans);
  return 0;
}