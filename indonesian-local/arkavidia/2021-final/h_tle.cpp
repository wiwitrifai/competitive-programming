#include <bits/stdc++.h>

using namespace std;

typedef long long LD;

inline bool eq(LD x, LD y) { return x == y; }
inline bool le(LD x, LD y) { return x <= y; }
inline bool lt(LD x, LD y) { return x < y; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD _x = 0, LD _y = 0) : x(_x), y(_y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  LD norm2() { return *this * *this; }
  bool operator<(point p) const { return eq(x, p.x) ? y < p.y : x < p.x; }
  bool operator==(point p) const { return eq(x, p.x) && eq(y, p.y); }
};

ostream& operator<<(ostream & os, point p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

// 1 : ccw, -1 : cw, 0 : colinear
int ccw(point a, point b, point c) {
  return sign((b-a) % (c-b));
}

inline void add_cw(vector<point> & vp, point & p) {
  int sz;
  while ((sz = vp.size()) >= 2 && ccw(p, vp[sz-1], vp[sz-2]) <= 0) {
    vp.pop_back();
  }
  vp.push_back(p);
}

inline void add_ccw(vector<point> & vp, point & p) {
  int sz;
  while ((sz = vp.size()) >= 2 && ccw(p, vp[sz-1], vp[sz-2]) >= 0) {
    vp.pop_back();
  }
  vp.push_back(p);
}

inline LD calc(vector<point> & vp, int from = 0) {
  LD ret = 0;
  for (int i = from; i + 1 < (int)vp.size(); ++i) {
    ret += vp[i] % vp[i+1];
  }
  return ret;
}

const int MAGIC = 400;

int main() {
  int n;
  scanf("%d", &n);
  vector<point> vp(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = point(x, y);
  }
  sort(vp.begin(), vp.end());
  vector<int> vx(n);
  for (int i = 0; i < n; ++i)
    vx[i] = vp[i].x;
  int q;
  scanf("%d", &q);
  // int MAGIC = sqrt(n);
  vector<LD> ans(q);
  vector<int> lef(q), rig(q);
  vector<vector<int>> groups((n + MAGIC - 1) / MAGIC);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", &lef[i], &rig[i]);
    lef[i] = lower_bound(vx.begin(), vx.end(), lef[i]) - vx.begin();
    rig[i] = upper_bound(vx.begin(), vx.end(), rig[i]) - vx.begin();
    int g = lef[i] / MAGIC;
    if (rig[i] <= (g+1) * MAGIC) {
      vector<point> upper, lower;
      for (int j = lef[i]; j < rig[i]; ++j) {
        add_cw(upper, vp[j]);
        add_ccw(lower, vp[j]);
      }
      ans[i] = calc(lower) - calc(upper);
      assert(le(0, ans[i]));
    } else {
      groups[g].push_back(i);
    }
  }
  vector<point> upper, lower, tmpup, tmplow;
  vector<long long> sumup, sumlow;
  upper.reserve(n);
  lower.reserve(n);
  sumup.reserve(n);
  sumlow.reserve(n);
  tmpup.reserve(MAGIC);
  tmplow.reserve(MAGIC);
  for (int g = 0; g < (int)groups.size(); ++g) {
    sort(groups[g].begin(), groups[g].end(), [&](int l, int r) {
      return rig[l] < rig[r];
    });
    int border = min((g+1) * MAGIC, n);
    int r = border;
    lower.clear();
    upper.clear();
    sumup.clear();
    sumlow.clear();
    for (int id : groups[g]) {
      while (r < rig[id]) {
        add_cw(upper, vp[r]);
        add_ccw(lower, vp[r]);
        sumup.resize(upper.size()-1);
        sumlow.resize(lower.size()-1);
        int sz;
        if ((sz = upper.size()) >= 2)
          sumup.push_back(sumup.back() + (upper[sz-1] % upper[sz-2]));
        else
          sumup.push_back(0);
        if ((sz = lower.size()) >= 2)
          sumlow.push_back(sumlow.back() + (lower[sz-2] % lower[sz-1]));
        else
          sumlow.push_back(0);
        ++r;
      }
      tmplow.clear();
      tmpup.clear();
      int itup = 0, itlow = 0;
      for (int i = border-1; i >= lef[id]; --i) {
        add_ccw(tmpup, vp[i]);
        add_cw(tmplow, vp[i]);
        if (tmpup.size() == 2 && ccw(tmpup[1], tmpup[0], upper[itup]) >= 0) {
          tmpup[0] = tmpup[1];
          tmpup.pop_back();
        }
        if (tmplow.size() == 2 && ccw(tmplow[1], tmplow[0], lower[itlow]) <= 0) {
          tmplow[0] = tmplow[1];
          tmplow.pop_back();
        }
        if (tmpup.size() == 1) {
          while (itup + 1 < (int)upper.size() && ccw(vp[i], upper[itup], upper[itup+1]) >= 0)
            ++itup;
        }
        if (tmplow.size() == 1) {
          while (itlow + 1 < (int)lower.size() && ccw(vp[i], lower[itlow], lower[itlow+1]) <= 0)
            ++itlow;
        }
      }
      ans[id] += calc(tmpup) - calc(tmplow) + sumup.back() - sumup[itup] + sumlow.back() - sumlow[itlow];
      ans[id] += upper[itup] % tmpup[0];
      ans[id] += tmplow[0] % lower[itlow];
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld.%d\n", ans[i] / 2, (ans[i] & 1) ? 5 : 0);
  }
  return 0;
}
