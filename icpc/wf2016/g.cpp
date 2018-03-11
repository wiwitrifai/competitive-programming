// by wiwit
#include <bits/stdc++.h>

using namespace std;

typedef long long LD;
inline int sign(LD x) { return x == 0 ? 0 : (x < 0 ? -1 : 1) ; }
inline bool eq(LD x, LD y) { return x == y; }
inline bool lt(LD x, LD y) { return x < y; }
inline bool le(LD x, LD y) { return x <= y; }
struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  bool operator==(point p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(point p) const { return eq(y, p.y) ? lt(x, p.x) : lt(y, p.y); }
};

int ccw(point p, point q, point r) {
  return sign((q-p) % (r-q));
}

const int N = 2048;

point a[N], b[N];
LD val[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<point, LD> > center;
  for (int i = 0; i < n; ++i) {
    int xa, xb, y;
    scanf("%d %d %d", &xa, &xb, &y);
    a[i] = point(xa, y);
    b[i] = point(xb, y);
    val[i] = abs((a[i]-b[i]).x);
    center.emplace_back(a[i],val[i]);
    center.emplace_back(b[i],val[i]);
  }
  sort(center.begin(), center.end());
  center.erase(unique(center.begin(), center.end()), center.end());
  long long ans = 0;
  for (auto it : center) {
    point c = it.first;
    vector<pair<point, int> > event;
    for (int i = 0; i < n; ++i) {
      if (eq(c.y, a[i].y)) continue;
      point p = a[i], q = b[i];
      if (lt(p.y, c.y)) {
        p = c * 2 - p;
        q = c * 2 - q;
      }
      if (ccw(c, p, q) < 0) swap(p, q);
      event.emplace_back(p, i+1);
      event.emplace_back(q, -(i+1));
    }
    sort(event.begin(), event.end(), [&](pair<point, int> le, pair<point, int> ri) {
      int rccw = ccw(c, le.first, ri.first);
      if (rccw == 0)
        return le.second > ri.second;
      return rccw > 0;
    });
    long long sum = it.second;
    ans = max(ans, sum);
    for (int i = 0; i < event.size(); ++i) {
      int id = event[i].second;
      if (id < 0)
        sum -= val[-id-1];
      else
        sum += val[id-1];
      ans = max(ans, sum);
//      cerr << id << " ? " << event[i].first.x << " "<< event[i].first.y << " " << sum << endl;
    }
  }
  printf("%lld\n", ans);
  return 0;
}