#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}

struct Fraction {
  int x, y;
  Fraction(int dx = 0, int dy = 1) {
    if (dx < 0 || dy < 0) {
      x = -1;
      y = 1;
      return;
    }
    int d = gcd(dx, dy);
    x = dx/d;
    y = dy/d;
  }
  bool operator==(Fraction f) {
    long long lhs = (long long)x * f.y, rhs = (long long)f.x * y;
    return lhs == rhs;
  }
  bool operator<(Fraction f) {
    long long lhs = (long long)x * f.y, rhs = (long long)f.x * y;
    return lhs < rhs;
  }
  bool operator<=(Fraction f) {
    return !(f < *this);
  }
};

ostream& operator<<(ostream& os, Fraction f) {
  if (f.x < 0)
    return os << -1;
  return os << f.x << "/" << f.y;
}

const int N = 2048;

int a[N], q[N];

Fraction meet[N][N];

int main() {
  freopen("falling.in", "r", stdin);
  freopen("falling.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i) {
    scanf("%d", q+i);
    --q[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      meet[i][j] = meet[j][i] = Fraction(a[j]-a[i], j-i);
    }
  }
  Fraction invalid(-1, 1);
  for (int i = 0; i < n; ++i) {
    Fraction ans = meet[i][q[i]];
    for (int j = 0; j < n; ++j) {
      if (meet[i][j] == invalid || meet[q[i]][j] == invalid) continue;
      if (meet[i][j] <= meet[q[i]][j]) {
        if (ans == invalid || meet[q[i]][j] < ans)
          ans = meet[q[i]][j];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
