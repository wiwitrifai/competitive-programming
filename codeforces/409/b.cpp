#include <bits/stdc++.h>

using namespace std;

struct point { long long x, y; };
// (LINE)
struct line { double a,b,c; };
void pointToLine(point p1, point p2, line *l) {
    if(p1.x == p2.x) {
      l->a = 1.0; l->b = 0.0; l->c = -p1.x;
  }
  else {
    l->a = -(double)(p1.y-p2.y)/(p1.x-p2.x);
    l->b = 1.0;
    l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
  }
}
double dist(line l, point p) {
  return (double)fabs((double)l.a * p.x + (double)l.b * p.y + (double)l.c) / sqrt((double)l.a * l.a + (double)l.b * l.b);
}

const int N = 1024;

point p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i].x = x, p[i].y = y;
  }
  p[n] = p[0];
  line l;
  pointToLine(p[n-1], p[1], &l);
  double ans = dist(l, p[0]);
  for (int i = 1; i < n; i++) {
    pointToLine(p[i-1], p[i+1], &l);
    ans = min(ans, dist(l, p[i]));
  }
  ans /= 2;
  printf("%.20lf\n", ans);
  return 0;
}