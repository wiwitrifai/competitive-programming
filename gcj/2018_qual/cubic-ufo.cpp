#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const LD eps = 1e-9;

inline bool eq(LD x, LD y) { return fabs(x - y) < eps; }
inline bool le(LD x, LD y) { return x < y + eps; }
inline bool lt(LD x, LD y) { return x + eps < y; }
inline int sgn(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  point rotate(LD sn, LD cs) { return point(cs * x - sn *y, sn * x + cs * y); }
  point rotate(LD angle) { return rotate(sin(angle), cos(angle)); }
  bool operator==(point p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(point p) const { return eq(y, p.y) ? lt(x, p.x) : lt(y, p.y); }
};

int ccw(point p, point q, point r) { return sgn((q-p) % (r-q)); }
LD dist2(point p, point q) { return (p-q) * (p-q); }

point pivot;
bool cmpAng(point p, point q) {
  int vccw = ccw(pivot, p, q);
  if (vccw == 0)
    return dist2(pivot, p) < dist2(pivot, q);
  return vccw > 0;
}

void convexHull(vector<point> & vp) {
  if (vp.size() < 3) return;
  for (int i = 1; i < vp.size(); ++i)
    if (vp[i] < vp[0])
      swap(vp[i], vp[0]);
  pivot = vp[0];
  sort(vp.begin() + 1, vp.end(), cmpAng);
  vector<point> ch;
  for (int i = 0; i < vp.size(); ++i) {
    int sz = ch.size();
    while ((sz = ch.size()) >= 2 && ccw(ch[sz-2], ch[sz-1], vp[i]) <= 0)
      ch.pop_back();
    ch.push_back(vp[i]);
  }
  vp = ch;
}

LD area(vector<point> & vp) {
  if (vp.size() <= 2) return 0;
  LD ret = vp.back() % vp[0];
  for (int i = 0; i + 1 < vp.size(); ++i)
    ret += vp[i] % vp[i+1];
  return fabs(ret) * 0.5;
}

bool debug = 1;
LD calc2(LD angx, LD angy) {
  vector<point> vp;
  for (int i = -1; i <= 1; i += 2) {
    for (int j = -1; j <= 1; j += 2) {
      for (int k = -1; k <= 1; k += 2) {
        LD x = i * 0.5, y = j * 0.5, z = k * 0.5;
        point p(y, z);
        p = p.rotate(angx);
        y = p.x, z = p.y;
        p = point(x, z);
        p = p.rotate(angy);
        x = p.x, z = p.y;
        vp.push_back(point(x, y));
      }
    }
  }
  convexHull(vp);
  LD res = area(vp);
  // if (debug) {
  //   cerr << angx << " " << angy << " " << res << endl;
  //   for (point p : vp)
  //     cerr << "(" << p.x << ", "<< p.y << ")" << endl;
  // }
  return res;
}

const int ITER = 100;
const LD PI = acos(-1);

bool found;
LD ansx, ansy, val;

LD calc1(LD target, LD angx) {
  LD lo = 0, hi = PI * 0.25, rlo = calc2(angx, lo), rhi = calc2(angx, hi);
  for (int it = 0; it < ITER; ++it) {
    if (le(target, rhi)) {
      LD mid = (lo + hi) * 0.5;
      LD res = calc2(angx, mid);
      if (fabs(res-target) < fabs(val-target)) {
        val = res;
        ansx = angx;
        ansy = mid;
      }
      if (res < target)
        lo = mid, rlo = res;
      else
        hi = mid, rhi = res;
    }
    else {
      assert(le(rlo, target));
      assert(le(rhi, target));
      LD l = (lo + lo + hi) / 3, r = (lo + hi + hi) / 3;
      LD resl = calc2(angx, l), resr = calc2(ansx, r);
      if (fabs(resl-target) < fabs(val-target)) {
        val = resl;
        ansx = angx;
        ansy = l;
      }
      if (fabs(resr-target) < fabs(val-target)) {
        val = resr;
        ansx = angx;
        ansy = r;
      }
      if (lt(resl, target) && lt(resr, target)) {
        if (resl < resr)
          lo = l, rlo = resl;
        else
          hi = r, rhi = resr;
      }
      else {
        if (resl < resr)
          hi = r, rhi = resr;
        else
          hi = l, rhi = resl;
      }
    }
  }
  return calc2(angx, (lo + hi) * 0.5);
}

int main() {
  // cerr << calc2(0, PI * 0.25) << endl;
  // cerr << calc2(PI * 0.25, PI * 0.25) << endl;
  // debug = 0;
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    double target;
    scanf("%lf", &target);
    ansx = 0, ansy = 0;
    val = calc2(ansx, ansy);
    LD lo = 0, hi = PI * 0.25, rlo = calc1(target, lo), rhi = calc1(target, hi);
    for (int it = 0; it < ITER; ++it) {
      if (le(target, rhi)) {
        LD mid = (lo + hi) * 0.5;
        LD res = calc1(target, mid);
        if (res < target)
          lo = mid, rlo = res;
        else
          hi = mid, rhi = res;
      }
      else {
        assert(le(rlo, target));
        assert(le(rhi, target));
        LD l = (lo + lo + hi) / 3, r = (lo + hi + hi) / 3;
        LD resl = calc1(target, l), resr = calc1(target, r);
        if (lt(resl, target) && lt(resr, target)) {
          if (resl < resr)
            lo = l, rlo = resl;
          else
            hi = r, rhi = resr;
        }
        else {
          if (resl < resr)
            hi = r, rhi = resr;
          else
            hi = l, rhi = resl;
        }
      }
    }
    vector<tuple<LD, LD, LD> > axis = {make_tuple(0.5, 0, 0), make_tuple(0, 0.5, 0), make_tuple(0, 0, 0.5)};
    printf("Case #%d:\n", tc);
    for (tuple<LD, LD, LD> & e : axis) {
      LD x, y, z;
      tie(x, y, z) = e;      
      point p(y, z);
      p = p.rotate(ansx);
      y = p.x, z = p.y;
      p = point(x, z);
      p = p.rotate(ansy);
      x = p.x, z = p.y;
      printf("%.15lf %.15lf %.15lf\n", (double)x, (double)y, (double)z);
      // cerr << val << endl;
    }
  }
  return 0;
}