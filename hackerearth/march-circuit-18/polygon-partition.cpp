#include <bits/stdc++.h>

using namespace std;
typedef int LD;
inline bool eq(LD a, LD b) { return a == b; }
inline bool lt(LD a, LD b) { return a  < b; }
inline bool le(LD a, LD b) { return a <= b; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y, id;
  point(LD x = 0, LD y = 0, LD id = -1) : x(x), y(y), id(id) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist2(point a, point b) {
  return (b - a) * (b - a);
}

LD area2(const vector< point > & P) {
  LD result = 0;
  result += P.back() % P[0];
  for(int i = 0; i+1 < (int)P.size(); ++i) {
    result += P[i] % P[i+1]; // cross(P[i], P[i+1]);
  }
  return abs(result);
}
point pivot;
bool angle_cmp(point a, point b) {
  if(ccw(pivot, a, b) == 0)
    return dist2(a, pivot) < dist2(b, pivot);
  return ccw(pivot, a, b) > 0;
}

// hasil convexHull tidak siklik
void convexHull(vector<point> & P) {
  int i, j, n = (int) P.size();
  if(n < 3) {
    return;
  }
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i] < P[PO]) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  // if point on boundary is included then uncomment this:
  // int k = (int)P.size()-1; while (k-1 > 0 && ccw(P[0], P[k-1], P.back()) == 0) k--;
  // reverse(P.begin() + k, P.end());
  vector<point> S;
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    // if point on boundary is included then ccw >= 0
    if(j < 1 || ccw(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  P = S;
}

// inside = -1, outside = 1, boundary = 0
int pointVsPolygon(point p, vector<point> & vp) {
  int n = vp.size();
  if (n == 1)
    return p == vp[0] ? 0 : 1;
  if (n == 2)
    return (ccw(vp[0], vp[1], p) == 0 && (vp[0] - p) * (vp[1] - p) <= 0) ? 0 : 1;
  if (ccw(vp[0], vp[n-1], p) > 0) return 1;
  if (ccw(vp[0], vp[1], p) < 0) return 1;
  int l = 1, r = n-1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (ccw(vp[0], vp[mid], p) > 0)
      l = mid;
    else
      r = mid;
  }
  return ccw(vp[r], vp[l], p);
}

const int N = 105;
vector<point> vp;
vector<vector<int> > ans;
vector<int> id;
LD best = -1;

void cek(vector<vector<int> > part) {
  LD tot = 0;
  for (auto ip : part) {
    vector<point> pp;
    for (int x : ip)
      pp.push_back(vp[x]);
    convexHull(pp);
    tot += area2(pp);
  }
  if (tot > best)
    ans = part, best = tot;
}
bool used[N];

int main() {
  time_t startt = clock();
  srand(time(0));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y, i));
    id.push_back(i);
  }
  ans.push_back(id);
  cek(ans);
  vector<point> ch = vp;
  convexHull(ch);
  for (int i = 0; i < ch.size(); ++i) {
    used[ch[i].id] = 1;
  }
  vector<int> p, q;
  for (int i = 0; i < ch.size(); ++i) {
    for (int j = i+1; j < ch.size(); ++j) {
      vector<int> a, b;
      for (int k = i; k <= j; ++k)
        a.push_back(ch[k].id);
      for (int k = 0; k < i; ++k)
        b.push_back(ch[k].id);
      for (int k = j+1; k < ch.size(); ++k)
        b.push_back(ch[k].id);
      if (a.size() <= 1 || b.size() <= 1) continue;
      vector<point> pa, pb;
      for (int x : a) pa.push_back(vp[x]);
      for (int x : b) pb.push_back(vp[x]);
      for (int k = 0; k < n; ++k) {
        if (used[k]) continue;
        if (pointVsPolygon(vp[k], pa))
          b.push_back(k);
        else if (pointVsPolygon(vp[k], pb))
          a.push_back(k);
        else if (rand() & 1)
          a.push_back(k);
        else
          b.push_back(k);
      }
      int cnt = rand() % 10;
      while (cnt--) {
        int le = rand() % pa.size();
        int ri = rand() % pb.size();
        swap(a[le], b[ri]);
      }
      vector<vector<int> > cur;
      cur.push_back(a);
      cur.push_back(b);
      cek(cur);
    }
  }
  while ((clock() - startt) * 1000.0 / CLOCKS_PER_SEC < 1975) {
    random_shuffle(id.begin(), id.end());
    vector<vector<int> > cur;
    int mi = (rand() % n) + 1;
    int now = 0;
    while ((n - now) >= 3) {
      int cnt = min(mi, (rand() % ((n-now-2))) + 3);
      vector<int> a;
      while (cnt--)
        a.push_back(id[now++]);
      cur.push_back(a);
    }
    vector<int> b;
    while (now < n)
      cur.back().push_back(id[now++]);
    cek(cur);
  }
  printf("%d\n", ans.size());
  for (auto ip : ans) {
    printf("%d", ip.size());
    sort(ip.begin(), ip.end());
    for (int x : ip)
      printf(" %d", x+1);
    printf("\n");
  }
  return 0;
}