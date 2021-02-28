#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct point {
  long long x, y;
  point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  long long operator*(point p) { return x * p.x + y * p.y; }
  long long operator%(point p) { return x * p.y - y * p.x; }
};

ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << "," << p.y << ")";
}

int main() {
  int n, l, r;
  scanf("%d %d %d", &n, &l, &r);
  point p1(l, 0), p2(r, 0);
  vector<point> points(n);
  vector<point> slope1, slope2;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    assert(y != 0);
    points[i] = point(x, y);
    if (y > 0) {
      slope1.emplace_back(points[i] - p1);
      slope2.emplace_back(points[i] - p2);
    }
    else {
      slope1.emplace_back(p1 - points[i]);
      slope2.emplace_back(p2 - points[i]);
    }
  }
  auto cmp = [](point lef, point rig) {
    return lef % rig > 0;
  };
  auto cmp_eq = [](point lef, point rig) {
    return lef % rig == 0;
  };
  sort(slope1.begin(), slope1.end(), cmp);
  sort(slope2.begin(), slope2.end(), cmp);
  slope1.erase(unique(slope1.begin(), slope1.end(), cmp_eq), slope1.end());
  slope2.erase(unique(slope2.begin(), slope2.end(), cmp_eq), slope2.end());
  auto get_pos1 = [&](point p) {
    point dir = p - p1;
    if (p.y < 0)
      dir = p1 - p;
    return lower_bound(slope1.begin(), slope1.end(), dir, cmp) - slope1.begin();
  };
  auto get_pos2 = [&](point p) {
    point dir = p - p2;
    if (p.y < 0)
      dir = p2 - p;
    return slope2.end() - lower_bound(slope2.begin(), slope2.end(), dir, cmp) - 1;
  };

  vector<vector<int>> presum(slope1.size(), vector<int>(slope2.size(), 0));
  vector<vector<int>> sufsum(slope1.size(), vector<int>(slope2.size(), 0));
  for (point p : points) {
    if (p.y > 0)
      ++presum[get_pos1(p)][get_pos2(p)];
    else
      ++sufsum[get_pos1(p)][get_pos2(p)];
  }
  for (int i = 0; i < (int)slope1.size(); ++i) {
    for (int j = 0; j < (int)slope2.size(); ++j) {
      if (i)
        presum[i][j] += presum[i-1][j];
      if (j)
        presum[i][j] += presum[i][j-1];
      if (i && j)
        presum[i][j] -= presum[i-1][j-1];
    }
  }
  for (int i = (int)slope1.size()-1; i >= 0; --i) {
    for (int j = (int)slope2.size()-1; j >= 0; --j) {
      if (i+1 < (int)slope1.size())
        sufsum[i][j] += sufsum[i+1][j];
      if (j+1 < (int)slope2.size())
        sufsum[i][j] += sufsum[i][j+1];
      if (i+1 < (int)slope1.size() && j+1 < (int)slope2.size())
        sufsum[i][j] -= sufsum[i+1][j+1];
    }
  }
  vector<long long> power2(n+1);
  power2[0] = 1;
  for (int i = 1; i < (int)power2.size(); ++i)
    power2[i] = 2LL * power2[i-1] % mod;

  long long ans = power2[sufsum[0][0]];
  for (int i = 0; i < (int)slope1.size(); ++i) {
    for (int j = 0; j < (int)slope2.size(); ++j) {
      long long cur = power2[presum[i][j]];
      cur -= power2[i ? presum[i-1][j] : 0];
      cur -= power2[j ? presum[i][j-1] : 0];
      cur += power2[(i && j) ? presum[i-1][j-1] : 0];
      cur %= mod;
      ans = (ans + cur * power2[sufsum[i][j]]) % mod;
    }
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
