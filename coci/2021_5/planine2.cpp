#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a , a) : b;
}


long long lcm(long long a, long long b) {
  return (a / gcd(a, b)) * b;
}

struct Fraction {
  long long up, down;
  Fraction(long long _up = 0, long long _down = 1) : up(_up), down(_down) {
    if (up == 0) {
      up = 0;
      down = 1;
      return;
    }
    assert(down != 0);
    if (down < 0) {
      up *= -1;
      down *= -1;
    }
    long long g = gcd(abs(up), abs(down));
    up /= g;
    down /= g;
  };

  Fraction operator+(Fraction frac) const {
    long long d = lcm(down, frac.down);
    long long u = up * (d / down) + frac.up * (d / frac.down);
    return Fraction(u, d);
  }

  Fraction operator-(Fraction frac) const {
    frac.up *= -1;
    return *this + frac;
  }

  Fraction operator*(Fraction frac) const {
    return Fraction(up * frac.up, down * frac.down);
  }

  Fraction operator/(Fraction frac) const {
    return Fraction(up * frac.down, down * frac.up);
  }

  bool operator<(Fraction frac) const {
    Fraction result = *this - frac;
    return result.up < 0;
  }

};

typedef long long LD;
struct point {
  LD x, y;
  point(LD _x = 0, LD _y = 0) : x(_x), y(_y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - y * p.x; }
};

int ccw(point a, point b, point c) {
  LD res = (b - a) % (c - a);
  return (res < LD(0)) ? -1 : (LD(0) < res) ? +1 : 0;
}

ostream& operator<<(ostream& os, Fraction f) {
  return os << f.up << "/" << f.down;
}

ostream& operator<<(ostream& os, point f) {
  return os << "(" << f.x << "," << f.y << ")";
}

int main() {
  int n;
  long long h;
  scanf("%d %lld", &n, &h);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  Fraction fh(h);
  vector<pair<Fraction, Fraction>> segments;
  for (int i = 2; i < n-1; i += 2) {
    if ((i & 1) == 0) {
      Fraction left = Fraction(x[i]) - (Fraction(x[i]) - Fraction(x[i-1])) * (fh - Fraction(y[i])) / (Fraction(y[i-1]) - Fraction(y[i]));
      for (int j = 0; j < i; ++j) {
        if (y[j] <= y[i]) continue;
        left = max(left, Fraction(x[i]) - (Fraction(x[i]) - Fraction(x[j])) * (fh - Fraction(y[i])) / (Fraction(y[j]) - Fraction(y[i])));
      }
      Fraction right = Fraction(x[i]) + (Fraction(x[i+1]) - Fraction(x[i])) * (fh - Fraction(y[i])) / (Fraction(y[i+1]) - Fraction(y[i]));
      for (int j = i+1; j < n; ++j) {
        if (y[j] <= y[i]) continue;
        right = min(right, Fraction(x[i]) + (Fraction(x[j]) - Fraction(x[i])) * (fh - Fraction(y[i])) / (Fraction(y[j]) - Fraction(y[i])));
      }
      segments.emplace_back(left, right);
    }
  }
  sort(segments.begin(), segments.end());
  int ans = 1;
  Fraction last = segments[0].second;
  for (int i = 1; i < (int)segments.size(); ++i) {
    if (!(last < segments[i].first)) {
      last = min(segments[i].second, last);
      continue;
    }
    ++ans;
    last = segments[i].second;
  }
  printf("%d\n", ans);
  return 0;
}
