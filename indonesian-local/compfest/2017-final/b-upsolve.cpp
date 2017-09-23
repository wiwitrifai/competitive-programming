/**
 * Upsolve after contest
 * Author  : Wiwit Rifa'i
 * Problem : B - Bersama Waifu
 * Status  : Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {};
};
long long cross(point a, point b, point c) {
  return 1LL * (a.x - b.x) * (c.y - b.y) - 1LL * (a.y - b.y) * (c.x - b.x);
}
long long dist2(point a, point b) {
  long long dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}
int sgn(long long x) {
  return (x > 0) - (x < 0);
}

bool isStrictIntersect(point a, point b, point c, point d) {
  return sgn(cross(a, b, c)) * sgn(cross(a, b, d)) < 0 && sgn(cross(c, d, a)) * sgn(cross(c, d, b)) < 0;
}

bool between(point a, point b, point c) {
  if (cross(a, b, c)) return false;
  return dist2(a, c) >= max(dist2(a, b), dist2(b, c));
}
const int N = 202;
point p[N];
vector<int> g[N];
int match[N], matched[N], vis[N];
bool dfs(int v) {
  if (vis[v])
    return false;
  vis[v] = 1;
  for (int u : g[v]) if (matched[u] == -1 || dfs(matched[u]))
    return match[v] = u, matched[u] = v, true;
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &p[i].x, &p[i].y);
    }
    point a, b;
    scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
    int inner = 0, outer = 0;
    vector<point> up, down;
    for (int i = 0; i < n; i++) {
      long long crs = cross(a, b, p[i]);
      if (crs == 0) {
        if (between(a, p[i], b))
          inner++;
        else
          outer++;
      }
      else if (crs > 0)
        up.push_back(p[i]);
      else
        down.push_back(p[i]);
    }
    memset(match, -1, sizeof match);
    memset(matched, -1, sizeof matched);
    for (int i = 0; i < up.size(); i++)
      g[i].clear();
    for (int i = 0; i < up.size(); i++) {
      for (int j = 0; j < down.size(); j++)
        if (!isStrictIntersect(up[i], down[j], a, b))
          g[i].push_back(j);
    }
    bool fnd = 1;
    while (fnd) {
      fnd = 0;
      fill(vis, vis+up.size(), 0);
      for (int i = 0; i < up.size(); i++) if (match[i] == -1)
        fnd |= dfs(i);
    }
    int ans = 0;
    for (int i = 0; i < up.size(); i++)
      outer += match[i] != -1;
    printf("%d\n", min(inner, outer));
  }
  return 0;
}