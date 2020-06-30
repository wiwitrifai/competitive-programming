#include <bits/stdc++.h>

using namespace std;

const int N = 2020, mod = 1e9 + 7;
const long long inf = 1e18;

long long dist[2][N];


struct line {
  long long a, b, get(long long x) {
    return a*x + b;
  }
  long double getd(long double x) {
    return x * a + b;
  }
};

struct convex_hull_trick {
  line * hull;
    // if find minimum value then change the comparation
  int size;
  convex_hull_trick(int sz) : size(0) {
    hull = new line[sz+1];
  }
  bool isbad(line prev, line cur, line next) {
    return (prev.b - cur.b) * (next.a - cur.a) >= (cur.b - next.b) * (cur.a - prev.a);
  }
  void add(line nl) {
    hull[size++] = nl;
    while(size > 2 && isbad(hull[size-3], hull[size-2], hull[size-1]))
      hull[size-2] = nl, size--;
  }

  long long query(long long x) {
    int l, r;
    l = 0; r = size-1;
    while(l < r) {
      int m = (l + r) >> 1;
      // this to find biggest
      if(hull[m].get(x) <= hull[m+1].get(x))
        l = m+1;
      else
        r = m;
    }
    return hull[l].get(x);
  }
};

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = -1;
    }
  }
  dist[0][0] = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    edges.emplace_back(u, v, w);
  }
  long long ans = 0;
  int cur = 0, bef = 1;
  for (int i = 0; i < m && q > 0; ++i) {
    swap(cur, bef);
    for (int j = 0; j < n; ++j)
      dist[cur][j] = -1;
    for (int j = 0; j < m; ++j) {
      int u, v, w;
      tie(u, v, w) = edges[j];
      if (dist[bef][v] >= 0)
        dist[cur][u] = max(dist[cur][u], dist[bef][v] + w);
      if (dist[bef][u] >= 0)
        dist[cur][v] = max(dist[cur][v], dist[bef][u] + w);
    }
    long long maxi = dist[cur][0];
    for (int j = 1; j < n; ++j)
      maxi = max(maxi, dist[cur][j]);
    ans += maxi;
    --q;
  }
  const long long inv2 = (mod + 1) / 2;
  if (q > 0) {
    vector<pair<long long, long long>> lines;
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      tie(u, v, w) = edges[i];
      lines.emplace_back(w, max(dist[cur][u], dist[cur][v]));
    }
    sort(lines.begin(), lines.end());
    convex_hull_trick cht(lines.size());
    for (auto l : lines) {
      cht.add((line){l.first, l.second});
    }
    ans %= mod;
    long long now = 1;
    for (int i = 0; now <= q && i+1 < cht.size; ++i) {
      long long b = cht.hull[i].b - cht.hull[i+1].b, a = cht.hull[i+1].a - cht.hull[i].a;
      if (a <= 0 || b <= 0) continue;
      long long til = min(b / a, (long long)q);
      if (now <= til) {
        long long s = til - now + 1;
        long long lef = cht.hull[i].get(now), rig = cht.hull[i].get(til);
        ans += (s * ((lef + rig) % mod) % mod) * inv2 % mod;
        ans %= mod;
        now = til + 1;
      }
    }
    if (now <= q) {
      int sz = cht.size;
      long long s = q - now + 1;
      long long lef = cht.hull[sz-1].get(now), rig = cht.hull[sz-1].get(q);
      ans += (s * ((lef + rig) % mod) % mod) * inv2 % mod;
      ans %= mod;
    }
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
