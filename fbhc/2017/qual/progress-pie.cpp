#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);

#define x first
#define y second

typedef pair< double, double > point;

double cross(point a, point b, point c) {
  return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}
point rotate(point a, double rad) {
  double si = sin(rad), co = cos(rad);
  return point(a.x * co + a.y * si, - a.x * si + a.y * co);
}
double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

int main() {
  time_t start_t = clock();
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int p, x, y;
    scanf("%d %d %d", &p, &x, &y);
    bool ans = 0;
    x -= 50; y -= 50;
    point ori = point(0, 0);
    point now = point(x, y);
    point bound = rotate(point(ori.x, ori.y + 50), (double)p * 2 * PI / 100);
    if (p > 0 && dist(ori, now) <= 50 + eps) {
      if (p == 100)
        ans = 1;
      if (now.x >= ori.x) {
        if (p >= 50)
          ans = 1;
        else {
          if (cross(bound, ori, now) >= -eps)
            ans = 1;
        }
      }
      else {
        if (p < 50)
          ans = 0;
        else {
          if (cross(bound, ori, now) >= -eps)
            ans = 1;
        }
      }
    }
    printf("Case #%d: %s\n", tc, ans ? "black" : "white");
    cerr << "TC #"<< tc << " : done! time: " << (double)(clock()-start_t) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}