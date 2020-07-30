#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

struct Fraction { // y / x
  long long y, x;
  Fraction(long long _y = 0, long long _x = 1) : y(_y), x(_x) {
    if (x < 0) {
      x *= -1;
      y *= -1;
    }
    if (y == 0)
      x = 1;
    long long g = gcd(x, abs(y));
    x /= g;
    y /= g;
  }
  Fraction operator*(Fraction f) {
    return Fraction(y * f.y, x * f.y);
  }
  long double operator*(long double v) {
    return v * y / x;
  }
  long double operator+(long double v) {
    return v + (long double)y / x;
  }
  Fraction operator-(Fraction f) {
    return Fraction(y * f.x - f.y * x, x * f.x);
  }

  bool operator<(const Fraction & f) const {
    return y * f.x < x * f.y;
  }

  long double get() {
    return (long double)y / x;
  }
};

struct Line {
  long double m, c;
  Line(long double _m = 0, long double _c = 0) : m(_m), c(_c) {
  }
  long double get(long double x) {
    return m * x + c;
  }
};

bool bad(Line lef, Line mid, Line rig) {
  return !((lef.c - mid.c) * (rig.m - mid.m) <
         (mid.c - rig.c) * (mid.m - lef.m));
}

struct Hull {
  vector<Line> hull;
  function<bool(long double, long double)> cmp;
  Hull(function<bool(long double, long double)> _cmp) : cmp(_cmp) {
  }
  void add(Line line) {
    int size = hull.size();
    while ((size = hull.size()) > 1 && bad(hull[size-2], hull[size-1], line))
      hull.pop_back();
    hull.push_back(line);
  }
  long double get(long double x) {
    int lo = 0, hi = (int)hull.size()-1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (cmp(hull[mid].get(x), hull[mid+1].get(x)))
        lo = mid + 1;
      else
        hi = mid;
    }
    return hull[lo].get(x);
  }
};


void solve() {
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int>> segments(n);
  for (int i = 0; i < n; ++i) {
    int xl, xr, y;
    scanf("%d %d %d", &xl, &xr, &y);
    segments[i] = make_tuple(y, xl, xr);
  }

  vector<pair<Fraction, int>> events;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (get<0>(segments[i]) <= get<0>(segments[j])) continue;
      long long y = get<0>(segments[i]) - get<0>(segments[j]);
      Fraction from(get<1>(segments[j]) - get<2>(segments[i]), y);
      Fraction til(get<2>(segments[j]) - get<1>(segments[i]), y);
      events.emplace_back(from, +1);
      events.emplace_back(til, -1);
    }
  }
  sort(events.begin(), events.end());
  Hull upper([&](long double a, long double b) { return a < b; });
  Hull lower([&](long double a, long double b) { return a > b; });
  vector<pair<int, int>> incre, decre;
  for (int i = 0; i < n; ++i) {
    int y, xl, xr;
    tie(y, xl, xr) = segments[i];
    incre.emplace_back(y, xr);
    decre.emplace_back(-y, -xl);
  }
  sort(incre.begin(), incre.end());
  sort(decre.begin(), decre.end());
  for (auto it : incre) {
    upper.add(Line(it.first, it.second));
  }
  for (auto it : decre) {
    lower.add(Line(-it.first, -it.second));
  }
  long double x = 0;
  if (!events.empty())
    x = events[0].first.get();
  long double ans = upper.get(x) - lower.get(x);
  int cnt = 0;
  for (auto & it : events) {
    if (cnt == 0 || cnt + it.second == 0) {
      x = it.first.get();
      long double cur = upper.get(x) - lower.get(x);
      if (ans > cur)
        ans = cur;
    }
    cnt += it.second;
  }
  printf("%.9lf\n", (double)ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
