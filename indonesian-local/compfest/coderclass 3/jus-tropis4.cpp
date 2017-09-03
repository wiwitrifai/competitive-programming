#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> point;
#define x first
#define y second
// (p-q) x (r-q)
long long cross(point p, point q, point r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

bool collinear(point a, point o, point b) {
    return cross(a, o, b) == 0;
}

// true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(p, q, r) > 0;
}

point pivot;

long long dist2(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(point a, point b) {
    if(collinear(pivot, a, b)) {
     return dist2(a, pivot) < dist2(b, pivot);
    }
    return ccw(pivot, a, b);
}

bool cmp(point a, point b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

// P tidak siklik, P[0] tidak mengulang di P.back()
// return convex hull siklik, P[0] mengulang di P.back()
vector<point> ConvexHull(vector<point> P) {
  int i, j, n = (int) P.size();
  if(n < 3)
    return P;
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(cmp(P[PO], P[i])) {
        PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  if(collinear(P.back(), P[0], P[1])) {
    vector< point > S;
    S.push_back(P[0]);
    S.push_back(P.back());
    return S;
  }
  sort(++P.begin(), P.end(), angle_cmp);
  int k = P.size() - 1;
  while(k && collinear(P[0], P[k-1], P[k])) k--;
  reverse(P.begin() + k, P.end());
  vector<point> S;
  S.push_back(P[n-1]);
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
    else S.pop_back();
  }
  S.pop_back();
  return S;
}

bool inPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size() - 1;
  for(int i = 0; i<n; i++) {
    long long cs = cross(vp[i+1], vp[i], p);
    if(cs == 0 && p.x <= max(vp[i].x, vp[i+1].x) && p.x >= min(vp[i].x, vp[i+1].x)
      && p.y <= max(vp[i].y, vp[i+1].y) && p.y >= min(vp[i].y, vp[i+1].y))
      return 1;
    if(wn == 0) {
      if(cs < 0)
        wn = -1;
      else
        if(cs > 0)
          wn = 1;
    }
    if(wn) {
      if(cs * wn <= 0)
        return 0;
    }
  }
  return 1;
}

int main(void)
{
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<point> p;
    for(int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      p.push_back(point(a, b));
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    vector<point> ch = ConvexHull(p);
    ch.push_back(ch[0]);
    while(m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      puts(inPolygon(point(x, y), ch) ? "YA" : "TIDAK");
    }
  }
  return 0;
}