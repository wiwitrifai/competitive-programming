#include <bits/stdc++.h>

using namespace std;

typedef long long LD;

inline int sign(LD x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
inline bool equal(LD x, LD y) { return x == y; }
inline bool eqless(LD x, LD y) { return x <= y; }
inline bool less(LD x, LD y) { return x < y; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(point p) { return x*p.x + y*p.y; } // dot
  LD operator%(point p) { return x*p.y - y*p.x; } // cross
  bool operator==(point p) const { return equal(x, p.x) && equal(y, p.y); }
  bool operator<(point p) const { return equal(y, p.y) ? x < p.x : y < p.y; }
};

int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

LD gcd(LD a, LD b) { return a ? gcd(b % a, a) : b; }

struct line {
  point a, ab; // p(t) = a + ab * t
  line(point ta, point tb) {
    if (tb < ta) swap(ta, tb);
    a = ta; ab = tb-ta;
    LD g = gcd(abs(ab.x), abs(ab.y));
    ab = ab / g;
  }
  point b() { return a + ab; }
  bool areParallel(line l) {
    return equal(ab % l.ab, 0);
  }
};

bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  LD ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  if (rs < 0) ls *= -1, rs *= -1;
  if (ls % rs) return 0;
  res = l1.a + l1.ab * (ls/rs);
  return 1;
}

void die() {
  puts("No");
  exit(0);
}

void answer(point p) {
  puts("Yes");
  printf("%I64d %I64d\n", p.x, p.y);
  exit(0);
}
const int N = 1e5 + 5;
bool can[N];

point pivot;
bool cmp(pair<point, int> le, pair<point, int> ri) {
  if (le.first == pivot) return true;
  if (ri.first == pivot) return false;
  point a = le.first - pivot, b = ri.first - pivot;
  point na = a * -1, nb = b * -1;
  if (a < na) a = na;
  if (b < nb) b = nb;
  return a % b > 0;
}
vector<pair<point, int> > all;

void process(point c) {
  pivot = c;
  sort(all.begin(), all.end(), cmp);
  for (int i = 1; i < all.size();) {
    int j = i;
    while (j < all.size() & ccw(pivot, all[i].first, all[j].first) == 0) ++j;
    int cnt = 0;
    for (int x = i; x < j; ++x)
      cnt += all[x].second == -1;
    if (cnt != 1) {
      for (int x = i; x < j; ++x)
        if (all[x].second != -1)
          can[all[x].second] = 0;
    }
    i = j;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  n <<= 1;
  vector<point> vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  line l1(vp[0], vp[1]);
  vector<point> cand;
  for (int i = 2; i < n; ++i) {
    line i0(vp[0], vp[i]), i1(vp[1], vp[i]);
    for (int j = i+1; j < n; ++j) {
      line ij(vp[i], vp[j]), j0(vp[0], vp[j]), j1(vp[1], vp[j]);
      point res;
      if (areIntersect(l1, ij, res)) {
        cand.push_back(res);
      }
      if (areIntersect(i0, j1, res)) {
        cand.push_back(res);
      }
      if (areIntersect(i1, j0, res)) {
        cand.push_back(res);
      }
    }
  }
  set<point> sp;
  for (point p : vp)
    all.push_back(make_pair(p, -1)), sp.insert(p);
  for (int i = 0; i < cand.size(); ++i) {
    point & p = cand[i];
    if (abs(p.x) > 1000000 || abs(p.y) > 1000000) continue;
    if (sp.count(p)) continue;
    sp.insert(p);
    all.push_back(make_pair(p, i));
    can[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    process(vp[i]);
  }
  for (int i = 0; i < cand.size(); ++i) {
    if (can[i])
      answer(cand[i]);
  }
  die();
  return 0;
}