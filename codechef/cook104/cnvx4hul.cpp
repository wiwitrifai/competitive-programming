#include <bits/stdc++.h>

using namespace std;

const int N = 256, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p &1)
      r = r * b % mod;
  return r;
}

long long pw[N];

typedef long long LD;
inline bool eq(LD a, LD b) { return a == b; }
inline bool lt(LD a, LD b) { return a < b; }
inline bool le(LD a, LD b) { return a <= b; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
point ori;

ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << "," <<p.y << ")";
}

point vp[N];
int n, cnt[N][N];

bool inside(point a, point p, point b) {
  if (ccw(ori, a, b) < 0)
    swap(a, b);
  return ccw(ori, a, p) > 0 && ccw(a, b, p) > 0 && ccw(b, ori, p) > 0;
}
int triangle(int i, int j, int k) {
  int ret = cnt[i][j] + cnt[j][k] + cnt[k][i];
  ret = abs(ret);
  if (inside(vp[i], vp[j], vp[k]) || inside(vp[i], vp[k], vp[j]) || inside(vp[j], vp[i], vp[k]))
    --ret;
  assert(ret >= 0);
  return ret;
}

long long calc(point pa, vector<pair<int, int>> &left, vector<pair<int, int>> &right) {
  auto cmp = [&](pair<int, int> lef, pair<int, int> rig)->bool {
    return sign((vp[lef.first] - pa) % (vp[rig.first] - pa)) < 0;
  };
  sort(left.begin(), left.end(), cmp);
  sort(right.begin(), right.end(), cmp);
  int i = 0;
  long long cur = 0, ans = 0;
  for (auto it : right) {
    int id = it.first;
    while (i < (int)left.size() && ccw(vp[id], pa, vp[left[i].first]) > 0) {
      cur += left[i].second;
      if (cur >= mod)
        cur -= mod;
      ++i;
    }
    ans = (ans + 1LL * cur * it.second) % mod;
  }
  if (ans < 0)
    ans += mod;
  return ans;
}

void solve() {
  pw[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i] = (pw[i-1] * 2LL) % mod;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp[i] = point(x, y);
  }
  for (int i = 1; i < n; ++i) {
    if (vp[i] < vp[0])
      swap(vp[0], vp[i]);
  }
  for (int i = 1; i < n; ++i) {
    vp[i] = vp[i] - vp[0];
  }
  vp[0] = vp[0] - vp[0];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      for (int k = 1; k < n; ++k) {
        if (k == i || k == j) continue;
        cnt[i][j] += inside(vp[i], vp[k], vp[j]);
      }
      cnt[j][i] = cnt[i][j];
      if (ccw(ori, vp[i], vp[j]) > 0)
        cnt[j][i] *= -1;
      else
        cnt[i][j] *= -1;
    }
  }
  long long ans = 0;
  for (int a = 0; a < n; ++a) {
    point pa = vp[a];
    for (int b = a+1; b < n; ++b) {
      point pb = vp[b];
      vector<pair<int, int>> left, right;
      for (int k = 0; k < n; ++k) {
        if (k == a || k == b) continue;
        if (ccw(pa, pb, vp[k]) > 0)
          left.emplace_back(k, pw[triangle(a, b, k)]);
        else
          right.emplace_back(k, pw[triangle(a, b, k)]);
      }
      long long sum_left = 0, sum_right = 0;
      for (auto it : left)
        sum_left += it.second;
      for (auto it : right)
        sum_right += it.second;
      sum_right %= mod;
      sum_left %= mod;
      ans = (ans + 1LL * sum_left * sum_right) % mod;
      ans = (ans - calc(pa, left, right) - calc(pb, right, left)) % mod;
      if (ans < 0) ans += mod;
    }
  }
  ans = (ans * powmod(2, mod - 2)) % mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
}

int main() {
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
