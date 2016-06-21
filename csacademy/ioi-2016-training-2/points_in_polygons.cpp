#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
typedef pair<long long, long long> point;
const int N = 1e5 + 5;
int n;
point vp[N];

// (p-q) x (r-q)
long long cross(point p, point q, point r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

int inPolygon(point p) {
  int wn = 0;
  for(int i = 0; i<n; i++) {
    long long cs = cross(vp[i+1], vp[i], p);
    if(cs == 0 && p.x <= max(vp[i].x, vp[i+1].x) && p.x >= min(vp[i].x, vp[i+1].x)
      && p.y <= max(vp[i].y, vp[i+1].y) && p.y >= min(vp[i].y, vp[i+1].y))
      return 1;
    if(vp[i].y <= p.y) {
      if(vp[i+1].y > p.y && cs > 0) {
        wn++;
      }
    }
    else {
      if(vp[i+1].y <= p.y && cs < 0) {
        wn--;
      }
    }
  }
  assert(abs(wn) < 2);
  return wn;
}

int main() {
  int m, np = 0;;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    scanf("%lld%lld", &vp[np].x, &vp[np].y);
    if(np == 0 || vp[np].x != vp[np-1].x || vp[np-1].y != vp[np].y)
      np++;
  }
  n = np-1;
  if(vp[0].x != vp[n].x || vp[0].y != vp[n].y)
    vp[++n] = vp[0];
  int ans = 0;
  while(m--) {
    point p;
    scanf("%d%d", &p.x, &p.y);
    if(inPolygon(p)) {
      // cerr << p.x << " " << p.y << endl;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}