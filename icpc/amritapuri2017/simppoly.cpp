#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
typedef pair<int, int> point;
#define x first
#define y second
inline int sign(long long x) { return x == 0 ? 0 : (x > 0 ? 1 : -1); }
inline long long cross(point a, point b, point c) {
  long long bx = b.x - a.x, by = b.y - a.y;
  long long cx = c.x - a.x, cy = c.y - a.y;
  long long crs = bx * cy - by * cx;
  return crs;
}

point p[N];
int pre[N], nxt[N], nodes[N];
int n;
bool cek(int u) {
  int a = pre[u], b = nxt[u];
  if (cross(p[a], p[u], p[b]) <= 0) return false;
  if (cross(p[a], p[b], p[pre[a]]) <= 0) return false;
  if (cross(p[a], p[b], p[nxt[b]]) <= 0) return false;
  for (int i = 0; i < n; ++i) {
    int v = nodes[i];
    if (v == a || v == u || v == b) continue;
    int r = nxt[v];
    if (r == a || r == u || r == b) continue;
    if (sign(cross(p[a], p[b], p[v])) * sign(cross(p[a], p[b], p[r])) >= 0) continue;
    if (sign(cross(p[v], p[r], p[a])) * sign(cross(p[v], p[r], p[b])) >= 0) continue;
    return false;
  }
  return true;
}

int main() {
  srand(time(0));
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &p[i].x, &p[i].y), nxt[i] = i+1, pre[i] = i-1, nodes[i-1] = i;
    }
    long long tot = cross({0,0}, p[n], p[1]);
    for (int i = 1; i < n; ++i)
      tot += cross({0,0}, p[i], p[i+1]);
    if (tot < 0)
      reverse(p+1, p+n+1);
    nxt[n] = 1;
    pre[1] = n;
    int need = min(500, n-3);
    vector<pair<int, int> > ans;
    while (need--) {
      int u = rand() % n;
      while (!cek(nodes[u])) {
        ++u;
        if (u >= n) u = 0;
      }
      --n;
      swap(nodes[u], nodes[n]);
      u = nodes[n];
      int a = pre[u], b = nxt[u];
      ans.emplace_back(a, b);
      pre[b] = a;
      nxt[a] = b;
    }
    for (auto it : ans)
      printf("%d %d\n", it.first, it.second);
  }
  return 0;
}