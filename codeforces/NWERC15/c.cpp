#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
};

long long cross(point a, point b, point c) {
  return 1LL * (a.x - b.x) * (c.y - b.y) - 1LL * (a.y - b.y) * (c.x - b.x);
}

bool isIntersect(point a, point b, point c, point d) {
  if (max(a.x, b.x) < min(c.x, d.x) || min(a.x, b.x) > max(c.x, d.x))
    return false;
  if (max(a.y, b.y) < min(c.y, d.y) || min(a.y, b.y) > max(c.y, d.y))
    return false;
  if (cross(a, b, c) * cross(a, b, d) > 0 || cross(c, d, a) * cross(c, d, b) > 0)
    return false;
  return true;
}

const int N = 2505;

point pw[N], pt[N];
int w[N];

vector<int> g[N];
int col[N];

bool dfs(int v, int c) {
  if (col[v] != -1)
    return col[v] == c;
  col[v] = c;
  c ^= 1;
  for (int u : g[v]) {
    if (!dfs(u, c))
      return false;
  }
  return true;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d %d", &pw[i].x, &pw[i].y);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", w+i, &pt[i].x, &pt[i].y);
    w[i]--;
  }
  for (int i = 0; i < m; i++) 
    for (int j = i+1; j < m; j++) {
      if (w[i] == w[j]) continue;
      if (isIntersect(pw[w[i]], pt[i], pw[w[j]], pt[j])) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  memset(col, -1, sizeof col);
  for (int i = 0; i < m; i++)
    if (col[i] == -1 && !dfs(i, 0)) {
      puts("impossible");
      return 0;
    }
  puts("possible");
  return 0;
}