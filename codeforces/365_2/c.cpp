#include <bits/stdc++.h>

using namespace std;

typedef pair< long long, long long > point;
const int N = 1e4 + 5;
#define x first
#define y second

point ch[N];
int n, w, v, u;
long long cross(point a, point b, point c) {
  return (a.x - b.x) * (c.y - b.y) - (c.x - b.x) * (a.y - b.y);
}

int main() {
  scanf("%d%d%d%d", &n, &w, &v, &u);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ch[i] = point(x, y);
  }
  point now = point(0, 0);
  bool down = true, up = true;
  for(int i = 0; i<n; i++) {
    long long cs = cross(point(now.x + v, now.y + u), now, ch[i]);
    up &= (cs >= 0);
    down &= (cs <= 0);
  }
  if(up || down) {
    double ans = (double)w/u;
    printf("%.15lf\n", ans);
    return 0;
  }
  for(int i = 0; i<n; i++) {
    if(cross(point(now.x + v, now.y + u), now, ch[i]) < 0) {
      now = ch[i];
    }
  }
  double ans = (double)now.x/v  + (double)(w-now.y) / u;
  printf("%.15lf\n", ans);
  return 0;
}