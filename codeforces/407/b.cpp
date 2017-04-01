#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

int deg[N], n, m, p[N], vs[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return 0;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return 1;
}

int main() {
  memset(p, -1, sizeof p);
  scanf("%d %d", &n, &m);
  int self = 0;
  int cnt = n;
  memset(vs, 0, sizeof vs);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    if (u == v)
      self++, vs[u] = 1;
    else {
      deg[u]++, deg[v]++;
      if (merge(u, v))
        cnt--;
    }
  }
  for (int i = 0; i < n; i++) if (!vs[i] && !deg[i])
    cnt--;
  if (cnt != 1) {
    puts("0");
    return 0;
  }
  long long ans = 1LL * (m-self) * self;
  ans += 1LL * self * (self-1) / 2;
  for (int i = 0; i < n; i++) {
    ans += 1LL * (deg[i]) * (deg[i]-1) / 2;
  }
  cout << ans << endl;

  return 0;
}