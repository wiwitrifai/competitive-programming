#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator==(point p) const { return x == p.x && y == p.y; }
  bool operator<(point p) const { return make_pair(x, y) < make_pair(p.x, p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }
  point operator+(point p) const { return point(x + p.x, y + p.y); }
  long long operator*(point p) const { return 1LL * p.x * x + 1LL * p.y * y; }
  long long operator%(point p) const { return 1LL * x * p.y - 1LL * p.x * y; }
};

int ccw(point p, point q, point r) {
  point pq = q - p, pr = r-p;
  long long crs = (pq % pr);
  if (crs == 0) return 0;
  return crs > 0 ? 1 : -1;
}
bool between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && (p.x-q.x) * (r.x-q.x) <= 0 && (p.y-q.y) * (r.y-q.y) <= 0;
}

// check if point p inside (CONVEX/CONCAVE) polygon vp
int inPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size() - 1;
  for(int i = 0; i<n; i++) {
    int cs = ccw(vp[i+1], vp[i], p);
    if(between(vp[i], p, vp[i+1])) return 1;
    if(vp[i].y <= p.y) {
      if(vp[i+1].y > p.y && cs > 0)
        wn++;
    }
    else {
      if(vp[i+1].y <= p.y && cs < 0)
        wn--;
    }
  }
  return wn;
}
point pivot;
long long dist2(point a, point b) {
  point ab = b - a;
  return ab * ab;
}

bool angle_cmp(point a, point b) {
  int res = ccw(pivot, a, b);
  if(res == 0)
    return dist2(a, pivot) < dist2(b, pivot);
  return res > 0;
}

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

int main() {
  int n, m;
  scanf("%d", &n);
  vector<point> z;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    z.push_back(point(x, y));
  }
  sort(z.begin(), z.end());
  z.erase(unique(z.begin(), z.end()), z.end());
  vector<point> ch = z;
  convexHull(ch);
  ch.push_back(ch[0]);
  if (ch.size() <= 3) {
    printf("0\n");
    return 0;
  }
  if (ch.size() == 4) {
    int cnt[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (point p : z) {
      if (p == ch[0] || p == ch[1] || p == ch[2]) continue;
      if (ccw(ch[0], ch[1], p) == 0)
        cnt[2]++;
      else if (ccw(ch[0], ch[2], p) == 0)
        cnt[1]++;
      else if (ccw(ch[2], ch[1], p) == 0)
        cnt[0]++;
      else
        cnt[0]++, cnt[1]++, cnt[2]++;
    }
    int tot = (cnt[0] > 0) + (cnt[1] > 0) + (cnt[2] > 0);
    if (tot < 2) {
      puts("0");
      return 0;
    }
    if (tot == 2) {
      if (cnt[0] == 0)
        z.erase(find(z.begin(), z.end(), ch[0]));
      else if (cnt[1] == 0)
        z.erase(find(z.begin(), z.end(), ch[1]));
      else
        z.erase(find(z.begin(), z.end(), ch[2]));
      ch = z;
      convexHull(ch);
      ch.push_back(ch[0]);
      assert(ch.size() > 4);
    }
  }
  scanf("%d", &m);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    point p (x, y);
    ans += inPolygon(p, ch) != 0;
  }
  printf("%d\n", ans);
  return 0;
}