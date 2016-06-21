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


bool inPolygon(point p) {

  int i, j = n-1;
  bool oddNodes=false;

  for (i=0; i<n; i++) {
    long long left = (p.y-vp[i].y)*(vp[j].x-vp[i].x), right = (p.x-vp[i].x)*(vp[j].y-vp[i].y);
    if(left == right && p.y <= max(vp[i].y, vp[j].y) && p.y >= min(vp[i].y, vp[j].y))
      return true;
    if (((vp[i].y< p.y && vp[j].y>=p.y) || (vp[j].y< p.y && vp[i].y>=p.y)) && (vp[i].x<=p.x || vp[j].x<=p.x)) {
      if(vp[j].y < vp[i].y) {
        left *= -1;
        right *= -1;
      }


      if (left<right) {
        // cerr << p.x << ' ' << p.y << " " << i << " " << j << endl;
        oddNodes=!oddNodes;
      }
    }
    j=i;
  }

  return oddNodes;
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
      ans++;
      // cerr << p.x << " yey " << p.y << endl;
    }
  }
  printf("%d\n", ans);
  return 0;
}