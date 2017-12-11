#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

struct point {
  int x, y;
  int col;
  point(int x = 0, int y = 0, int col = 0) : x(x), y(y), col(col) {}
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator+(point p) { return point(x + p.x, y + p.y); }
  long long operator*(point p) { return 1LL * x * p.x + 1LL * y * p.y; }
  long long operator%(point p) { return 1LL * x * p.y - 1LL * y * p.x; }
  bool operator<(const point p) const {
    if (p.y > y) return 1;
    if (p.y < y) return 0;
    return x < p.x;
  }
  bool operator==(const point p) const { return x == p.x && y == p.y; }
};

int ccw(point p, point q, point r) {
  point pq = q - p, qr = r - q;
  long long crs = pq % qr;
  if (crs == 0) return 0;
  return crs > 0 ? 1 : -1;
}

point pivot;

bool cmp(point a, point b) {
  return ccw(pivot, a, b) > 0;
}

vector<point> sortCycle(vector<point> vp, point pivot) {
  ::pivot = pivot;
  vector<point> up, down;
  for (point p : vp) {
    if (p == pivot) continue;
    if (p < pivot)
      down.push_back(p);
    else
      up.push_back(p);
  }
  sort(up.begin(), up.end(), cmp);
  sort(down.begin(), down.end(), cmp);
  for (point p : down)
    up.push_back(p);
  return up;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<point> vp;
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      vp.push_back(point(x, y, 0)); // red
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      vp.push_back(point(x, y, 1)); // blue
    }
    int ans = min(n, m);
    for (point p : vp) {
      vector<point> sp = sortCycle(vp, p);
      int s = 0, sz = sp.size();
      int blue = 0;
      int nred = n, nblue = m;
      if (p.col)
        nblue--;
      else
        nred--;
      for (int i = 0; i < sz; i++) {
        if (s == 0) {
          s++;
          blue = sp[i].col;
        }
        int j;
        while (s < sz && ccw(sp[i], p, sp[j = ((i + s) % sz)]) < 0) blue += sp[j].col, s++;
        ans = min(ans, min(blue + nred - (s - blue), (s - blue) + (nblue - blue)));
        s--;
        blue -= sp[i].col;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}