#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const point& b) {
    if (x != b.x)
      return x < b.x;
    return y < b.y;
  }
  point operator+(const point& b) {
    return point(x + b.x, y + b.y);
  }
};

const int N = 55;

point a[N], b[N], s, t;
int n, p[N];


point reflect(point now, int i) {
  if (a[i].x == b[i].x)
    return point(2 * a[i].x - now.x, now.y);
  else
    return point(now.x, 2 * a[i].y - now.y);
}

int sign(long long x) {
  return (x > 0) - (x < 0);
}

long long cross(point a, point b, point c) {
  return 1LL * (a.x - b.x) * (c.y - b.y) - 1LL * (a.y - b.y) * (c.x - b.x);
}

int intersect_time(point c, point d, int i) {
  if (d.x == 0) {
    if (a[i].y != b[i].y || c.x < a[i].x || c.x > b[i].x) return -1;
    return (a[i].y - c.y) * sign(d.y);
  }
  if (d.y == 0) {
    if (a[i].x != b[i].x || c.y < a[i].y || c.y > b[i].y) return -1;
    return (a[i].x - c.x) * sign(d.x);
  }
  if (sign(cross(c, c+d, a[i])) * sign(cross(c, c+d, b[i])) > 0)
    return -1;
  if (a[i].y != b[i].y)
    return (a[i].x - c.x) * sign(d.x) * abs(d.y);
  else
    return (a[i].y - c.y) * sign(d.y) * abs(d.x);
}


bool cek(int k) {
  point ps = s, pt = t;
  for (int i = k-1; i >= 0; i--)
    pt = reflect(pt, p[i]);
  if (pt.x == ps.x && pt.y == ps.y)
    return false;
  int tcur = 0;
  for (int i = 0; i <= k; i++) {
    point dir(pt.x - ps.x, pt.y - ps.y);
    int tnow = intersect_time(ps, dir, p[i]);
    if (tnow < tcur) return false;
    for (int j = i+1; j <= n; j++) {
      if (p[j] == n) continue;
      int temp = intersect_time(ps, dir, p[j]);
      if (tcur <= temp && temp < tnow)
        return false;
    }
    tcur = tnow;
    ps = reflect(ps, p[i]);
    pt = reflect(pt, p[i]);
  }
  return true;
}

int main() {
  s = {0, 0};
  scanf("%d %d %d", &n, &t.x, &t.y);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
    if (b[i] < a[i])
      swap(a[i], b[i]);
  }
  a[n] = b[n] = t;
  iota(p, p+n+1, 0);
  int ans = -1;
  do {
    for (int i = 0; i <= n; i++)
      if (p[i] == n && is_sorted(p+i+1, p+n+1) && cek(i)) {
        ans = max(ans, i);
      }
  } while (next_permutation(p, p+n+1));
  if (ans < 0)
    puts("impossible");
  else
    printf("%d\n", ans);
  return 0;
}