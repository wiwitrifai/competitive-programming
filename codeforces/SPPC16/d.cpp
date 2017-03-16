#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {
  }
  point operator-(point p) {
    return point(x - p.x, y - p.y);
  }
  double operator*(point p) {
    return x * p.y - p.x * y;
  }
  double length() {
    return hypot(x, y);
  }
};

bool circle2PtsRad(point p1, point p2, double r, point *c) { // answer at *c
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
    double det = r * r / d2 - 0.25;
  if(det<0.0) return false;
  double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h;
  return true;
}

double area(point a, point b, point c) {
  return fabs(a * b + b * c + c * a)/2;
}
double RLuar(point a, point b, point c) {
  double ab = (a-b).length(), bc = (b-c).length(), ac = (a-c).length();
  return ab * bc * ac / (4.0 * area(a, b, c));
}

const int N = 105;

point p[N];
bool infect[N];
char s[10];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d %s", &x, &y, s);
    p[i] = point(x, y);
    infect[i] = s[0] == 'I';
  }
  bool found = n < 3;
  for (int i = 0; i < n && !found; i++) {
    for (int j = i+1; j < n && !found; j++) {
      for (int k = j+1; k < n && !found; k++) {
        if (area(p[i], p[j], p[k]) < eps)
          continue;
        double r = RLuar(p[i], p[j], p[k]);
        point c(0, 0);
        circle2PtsRad(p[i], p[j], r, &c);
        if (fabs((c - p[k]).length() - r) > eps)
          circle2PtsRad(p[j], p[i], r, &c);
        found = 1;
        for (int z = 0; z < n; z++) {
          if (infect[z]) {
            if ((p[z]-c).length() > r + eps) {
              found = 0;
              break;
            }
          }
          else {
            if ((p[z]-c).length() + eps < r) {
              found = 0;
              break;
            }
          }
        }
      }
      if (found)
        break;
      double r = (p[i]-p[j]).length()/2;
      point c((p[i].x + p[j].x)/2, (p[i].y + p[j].y)/2);
      found = 1;
      for (int z = 0; z < n; z++) {
        if (infect[z]) {
          if ((p[z]-c).length() > r + eps) {
            found = 0;
            break;
          }
        }
        else {
          if ((p[z]-c).length() + eps < r) {
            found = 0;
            break;
          }
        }
      }    
    }
  }
  puts(found ? "No" : "Yes");
  return 0;
}