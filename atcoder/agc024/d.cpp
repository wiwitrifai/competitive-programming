#include <bits/stdc++.h>

using namespace std;

const int N = 505;

const unsigned long long inf = (1ULL << 63) - 1;

vector<int> g[N];
int p[N], lv[N];

void dfs(int v, int par) {
  p[v] = par;
  for (int u : g[v]) if (u != par) {
    lv[u] = lv[v] + 1;
    dfs(u, v);
  }
}
int deg[N];

unsigned long long mul(unsigned long long a, unsigned long long b) {
  if (a == 0 || b == 0)
    return 0;
  if (inf / a < b) return inf;
  return min(a * b, inf);
}

int n;
unsigned long long calc2() {
  for (int i = 0; i < n; ++i) deg[i] = 0;
  unsigned long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += lv[i] == 0;
    int cur = 0;
    for (int u : g[i]) if (lv[u] == lv[i]+1) ++cur;
    deg[lv[i]] = max(deg[lv[i]], cur);
  }
  for (int i = 0; i <= n; ++i)
    if (deg[i] > 0)
      cnt = mul(cnt, deg[i]);
  return cnt;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  lv[0] = 0;
  dfs(0, 0);
  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (lv[i] > lv[x]) x = i;
  }
  lv[x] = 0;
  dfs(x, -1);
  int y = x;
  for (int i = 0; i < n; ++i)
    if (lv[i] > lv[y]) y = i;
  unsigned long long depth = lv[y]/2 + 1, cnt = 1;
  // cerr << lv[y] << endl;
  if (lv[y] & 1) {
    for (int i = 1; i < depth; ++i) {
      y = p[y];
    }
    int u = p[y], v = y;
    lv[u] = lv[v] = 0;
    dfs(u, v);
    dfs(v, u);
    cnt = calc2();
  }
  else {
    for (int i = 1; i < depth; ++i) {
      y = p[y];
    }
    lv[y] = 0;
    dfs(y, y);
    cnt = calc2();
    for (int u : g[y]) {
      lv[y] = lv[u] = 0;
      dfs(u, y);
      dfs(y, u);
      cnt = min(calc2(), cnt);
    }
  }
  cout << depth << " " << cnt << endl;
  return 0;
}