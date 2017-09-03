#include <bits/stdc++.h>

using namespace std;

const int N = 10101, inf = 1e9 + 7;
struct point {
  double x, y;
  point (double x = 0, double y = 0) : x(x), y(y) {
  }
  point operator/(int d) {
    return point(x/d, y/d);
  }
  point operator-(point other) const {
    return point(x-other.x, y-other.y);
  }
  point operator+(point other) {
    return point(x+other.x, y+other.y);
  }
  double dist(point other = point()) {
    double dx = x - other.x, dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
  }
  bool operator<(point b) const {
    if (y == b.y)
      return x < b.x;
    return y < b.y;
  }
};
bool cmp(point a, point b) {
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}
void upd(point & a, point b) {
  if (cmp(b, a))
    a = b;
}
point p[N];
const double eps = 1e-5;

bool zero(double z) {
  return fabs(z) < eps;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n;
    long long r;
    scanf("%d %lld", &n, &r);
    r *= 2;
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      p[i] = point(x, y);
    }
    sort(p, p+n, cmp);
    set< point > st;
    double nearest = inf;
    point ans;
    for (int i = 0, j = 0; i < n; i++) {
      while (j < i && p[i].x - p[j].x > nearest) st.erase(p[j++]);
      auto it = st.lower_bound(point(-1, p[i].y-nearest));
      while (it != st.end()) {
        if (it->y > p[i].y + r) break;
        double cur = p[i].dist(*it);
        if (zero(cur-nearest)) {
          nearest = cur;
          upd(ans, (p[i] + *it)/2);
        }
        else if (nearest > cur) {
          nearest = cur;
          ans = (p[i] + *it)/2;
        }
        it++;
      }
      st.insert(p[i]);
    }
    if (nearest > r )
      printf("Case #%d: -1\n", tc);
    else
      printf("Case #%d: %.1lf %.1lf\n", tc, (double)ans.x, (double)ans.y);
  }
  return 0;
}