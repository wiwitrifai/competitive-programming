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
    if(cmp(P[i], P[PO])) {
        PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  int k = P.size() - 1;
  if (collinear(P[0], P[1], P.back())) {
    vector< point > res;
    res.push_back(P[0]);
    res.push_back(P.back());
    return res;
  } 
  while(k && collinear(P[0], P[k-1], P[k])) k--;
  reverse(P.begin() + k, P.end());
  vector<point> S;
  S.push_back(P[k]);
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i <= k) {
    j = (int) S.size() - 1;
    if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
    else S.pop_back();
  }
  return S;
}

bool isCCW(vector< point > v) {
  if (v.size() < 3) return true;
  for (int i = 0; i < v.size(); i++) {
    long long crs = cross(v[i], v[i+1], v[i+2]);
    if (crs == 0) continue;
    return crs > 0;
  } 
}

vector< point > rotate(vector< point > ch) {
  int id = 0;
  for (int i = 0; i < ch.size(); i++) {
    if (ch[i] < ch[id]) id = i;
  }
  if (id != 0) {
    vector< point > ret;
    for (int i = id; i < ch.size(); i++)
      ret.push_back(ch[i]);
    for (int i = 0; i < id; i++)
      ret.push_back(ch[i]);
    return ret;
  }
  else
    return ch;
}

int main() {
  int n;
  scanf("%d", &n);
  vector< point > vp;
  for (int i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    vp.push_back(make_pair(x, y));
  }
  vector< point > ch = ConvexHull(vp);
  while (ch.size() > 1 && ch[0] == ch.back())
    ch.pop_back();
  if (ch.size() > 2 && isCCW(ch))
    reverse(ch.begin(), ch.end());
  ch = rotate(ch);
  for (int i = 0; i < ch.size(); i++) {
    printf("#%d: %lld %lld\n", i+1, ch[i].first, ch[i].second);
  } 
  return 0;
}