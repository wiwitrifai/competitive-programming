#include <bits/stdc++.h>

using namespace std;

struct point {
  double x, y;
  point(double xx = 0, double yy = 0) : x(xx), y(yy) {
  }
  point operator-(point other) {
    return point(x-other.x, y-other.y);
  }
  point operator+(point other) {
    return point(x+other.x, y+other.y);
  }
  point operator*(double mul) {
    return point(x * mul, y * mul);
  }
  point operator/(double d) {
    return point(x/d, y/d);
  }
  double dist2() {
    return x * x + y * y;
  }
};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    point from, to;
    double s;
    scanf("%lf %lf", &to.x, &to.y);
    scanf("%lf %lf %lf", &from.x, &from.y, &s);
    s *= s;
    point vs = to - from;
    double len = sqrt(vs.dist2());
    bool ok = 1;
    for (int i = 0; i < 5; i++) {
      point cur;
      double v;
      scanf("%lf %lf %lf", &cur.x, &cur.y, &v);
      v *= v;
      double lo = 0, hi = len;
      for (int j = 0; j < 1000; j++) {
        double ml = (lo * 2 + hi)/3, mh = (lo + hi * 2) /3;
        point pl =  from + (vs * (ml/len)), ph = from + (vs * (mh/len));
        double tl = (pl-cur).dist2(), th = (ph-cur).dist2();
        if (tl < th)
          hi = mh;
        else
          lo = ml;
      }
      hi = len;
      for (int j = 0; j < 1000; j++) {
        double ml = (lo + lo + hi)/3, mh = (lo + hi * 2) /3;
        point pl =  from + (vs * (ml/len)), ph = from + (vs * (mh/len));
        double tl = (pl-cur).dist2()/v - ml * ml/s, th = (ph-cur).dist2()/v - mh * mh/s;
        if (tl < th)
          hi = mh;
        else
          lo = ml;
      }
      point pp = from + (vs * (lo/len));
      double tt = (pp-cur).dist2()/v - lo * lo/s;
      if (tt < 0)
        ok = 0;
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}