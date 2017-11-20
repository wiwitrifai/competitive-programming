#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  bool operator<(point p) const {
    if (fabs(x - p.x) > EPS)
      return x < p.x;
    return y < p.y;
  }
  bool operator==(point p) const {
    return (fabs(x - p.x) < EPS) && (fabs(y - p.y) < EPS);
  }
  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }
  point operator*(double scale) const { return point(x * scale, y * scale); }
  point operator/(double scale) const { return point(x / scale, y / scale); }
};

double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

// rotate p by theta degrees CCW w.r.t origin(0, 0)
point rotate(point p, double tetha) {
  // rotate matrix R(theta0 = [cos(theta) -sin(theta)]
  //            [sin(theta)  cos(theta)]
  double rad = tetha * PI / 180.0;
  return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
double cross(point a, point b) {
  return a.x * b.y - a.y * b.x;
}
double dot(point a, point b) {
  return a.x * b.x + a.y * b.y;
}
double norm_sq(point p) {
  return dot(p, p);
}
double norm(point p) {
  return sqrt(dot(p, p));
}
// return 1 = ccw, 0 = colinear, -1 = cw
int ccw(point p, point q, point r) {
  point pq = q - p, pr = r-p;
  double crs = cross(pq, pr);
  if (fabs(crs) < EPS) return 0;
  return crs > 0 ? 1 : -1;
}
bool between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && (p.x-q.x) * (r.x-q.x) < EPS && (p.y-q.y) * (r.y-q.y) < EPS;
}
// calculate angle between OA and OB
double angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// (LINE)
struct line { double a,b,c; };
void pointToLine(point p1, point p2, line& l) {
  if(fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  }
  else {
    l.a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - (l.b * p1.y);
  }
}
bool areParallel(line l1, line l2) {
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(line l1, line l2) {
  return areParallel(l1, l2) && (fabs(l1.c-l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point& p) {
  if(areParallel(l1, l2)) return false;
  
  p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
  if(fabs(l1.b) > EPS)
    p.y = -(l1.a*p.x + l1.c)/l1.b;
  else
    p.y = -(l2.a*p.x + l2.c)/l2.b;
  return true;
}

double distToLine(point p, point a, point b, point & c) {
  point ap = p-a, ab = b-a;
  double u = dot(ap, ab) / norm_sq(ab);
  c = a + ab * u;
  return dist(p, c);
}
double distToLineSegment(point p, point a, point b, point &c) {
  point ap = p-a, ab = b-a;
  if (a == b) {
    c = a;
    return dist(p, c);
  }
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) c = a;
  else if (u > 1.0) c = b;
  else c = a + ab * u;
  return dist(p, c);
}

// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line& l) {
  l.a = -m;
  l.b = 1;
  l.c = -((l.a * p.x) + (l.b * p.y));
}
// find point on line l which is closest to p
void closestPoint(line l, point p, point& ans) {
  line perpendicular;
  if (fabs(l.b) < EPS) {
    ans.x = -l.c; ans.y = p.y;
    return;
  }
  if (fabs(l.a) < EPS) {
    ans.x = p.x; ans.y = -l.c;
    return;
  }
  pointSlopeToLine(p, 1/l.a, perpendicular);
  areIntersect(l, perpendicular, ans);
}
// return the reflection of point on a line
void reflectionPoint(line l, point p, point &ans) {
  point b;
  closestPoint(l, p, b);
  ans = b * 2 - p;
}

vector<point> interCircle(point o1, double r1, point o2, double r2) {
  double d2 = norm_sq(o1 - o2);
  double d = sqrt(d2);
  if (d < EPS) return {};
  if (d < abs(r1-r2)) return {};
  if (d > r1+r2) return {};
  point u = (o1+o2) * 0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  double A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
  point v = point(o1.y-o2.y, -o1.x+o2.x) * (A / (2*d2));
  return {u+v, u-v};
}
point inCenter(point &A, point &B, point &C) { // 内心
  double a = norm(B-C), b = norm(C-A), c = norm(A-B);
  return (A * a + B * b + C * c) / (a + b + c);
}
point circumCenter(point &a, point &b, point &c) { // 外心
  point bb = b - a, cc = c - a;
  double db = norm_sq(bb), dc = norm_sq(cc), d= 2*cross(bb, cc);
  return a-point(bb.y*dc-cc.y*db, cc.x*db-bb.x*dc) / d;
}
point orthoCenter(point &a, point &b, point &c) { // 垂心
  point ba = b - a, ca = c - a, bc = b - c;
  double y = ba.y * ca.y * bc.y,
    A = ca.x * ba.y - ba.x * ca.y,
    x0= (y+ca.x*ba.y*b.x-ba.x*ca.y*c.x) / A,
    y0= -ba.x * (x0 - c.x) / ba.y + ca.y;
  return point(x0, y0);
}

void testInterCircle() {
  point o1, o2;
  double r1, r2;
  cin >> o1.x >> o1.y;
  cin >> o2.x >> o2.y;
  cin >> r1 >> r2;
  vector<point> res = interCircle(o1, r1, o2, r2);
  for (point p : res) {
    cout << p.x << " " << p.y << endl;
    cerr << " dist to o1 : " << sqrt(norm_sq(p-o1)) << endl;
    cerr << " dist to o2 : " << sqrt(norm_sq(p-o2)) << endl;
  }
}
double heron(double a, double b, double c) {
  double s = (a + b + c) * 0.5;
  return sqrt(s * (s - a)) * sqrt((s-b) * (s-c));
}
// area by cross
double areaTriangle(point a, point b, point c) {
  return fabs(cross(a-b, c-b)) * 0.5;
}

double rInCircle(double ab, double bc, double ca) {
  return heron(ab, bc, ca) / (0.5 * (ab + bc + ca));
}
double rInCircle(point a, point b, point c) {
  return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}
// return 1 if there is an inCircle center, return 0 otherwise
// if return 1, ctr will be the inCircle cnter, and r is its radius
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
  r = rInCircle(p1, p2, p3);
  if (fabs(r) < EPS) return 0;
  line l1, l2;
  double ratio = dist(p1, p2) / dist(p1, p3);
  point p = p2 + (p3-p2) * (ratio/(1 + ratio));
  pointToLine(p1, p, l1);

  ratio = dist(p2, p1) / dist(p2, p3);
  p = p1 + (p3-p1) * (ratio/(1 + ratio));
  pointToLine(p2, p, l2);

  return areIntersect(l1, l2, ctr);
}
double rCircumCircle(double ab, double bc, double ca) {// = BC / 2 sin(<ABC)
  return ab * bc * ca / (4.0 * heron(ab, bc, ca));
}
double rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}


point perp(const point& p) {
  return point(p.y, -p.x);
}
vector<pair<point, point> > tangent2Circle(point o1, double r1, point o2, double r2){
  vector<pair<point, point> > ret;
  double d_sq = norm_sq( o1 - o2);
  if( d_sq < EPS ) return ret;
  double d = sqrt( d_sq );
  point v = ( o2 - o1 ) / d;
  for( int sign1 = 1 ; sign1 >= -1 ; sign1 -= 2 ){
    double c = ( r1 - sign1 * r2 ) / d;
    if( c * c > 1 ) continue;
    double h = sqrt(max( 0.0 , 1.0 - c * c ) );
    for( int sign2 = 1 ; sign2 >= -1 ; sign2 -= 2 ){
      point n;
      n.x = v.x * c - sign2 * h * v.y;
      n.y = v.y * c + sign2 * h * v.x;
      point p1 = o1 + n * r1;
      point p2 = o2 + n * ( r2 * sign1 );
      if( fabs( p1.x - p2.x ) < EPS and
          fabs( p1.y - p2.y ) < EPS )
        p2 = p1 + perp( o2 - o1 );
      ret.push_back( { p1 , p2 } );
    }
  }
  return ret;
}


void testInCircle() {
  point a, b, c;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;
  point p = inCenter(a, b, c);
  cout << p.x << " " << p.y << endl;
  point q;
  cout << distToLineSegment(p, a, b, q) << " " << distToLineSegment(p, b, c, q) << " " << distToLineSegment(p, a, c, q) << endl;
  cout << rInCircle(a, b, c) << endl;
}
void testCircumCircle() {
  point a, b, c;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;
  point p = circumCenter(a, b, c);

}
void testOrthoCenter() {
  point a, b, c;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;
  point p = orthoCenter(a, b, c);
}


int main() {
  testInCircle();
  return 0;
}