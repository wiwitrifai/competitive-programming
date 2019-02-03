#include <bits/stdc++.h>

using namespace std;

typedef long long LD;

inline bool eq(LD x, LD y) { return x == y; }
inline bool le(LD x, LD y) { return x <= y; }
inline bool lt(LD x, LD y) { return x < y; }
inline int sign(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(LD s) { return point(x * s, y * s); }
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
  LD norm2() { return *this * *this; }
  bool operator==(point p) { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(point p) { return eq(x, p.x) ? y < p.y : x < p.x; }
  mutable function<const point*()> succ;
};

int ccw(point a, point b, point c) {
  return sign((b - a) % (c - b));
}

struct HullDynamic : public multiset<Point> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return eq(y->x, z->x) && le(;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b; // min: reverse it
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m); // beware overflow!
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

int main() {

  return 0;
}