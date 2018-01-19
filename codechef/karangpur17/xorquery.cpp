#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, LG = 21;

int p[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return false;
  if (p[u] > p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return true;
}
vector<pair<int, int> > g[N];
int val[N];
void dfs(int v, int par = -1) {
  for (auto it : g[v]) if (it.first != par) {
    int u = it.first;
    val[u] = val[v] ^ it.second; 
    dfs(u, v);
  }
}

int query(int u, int v) {
  if (find(u) != find(v)) return -1;
  return val[u] ^ val[v];
}

int ty[N], a[N], b[N], c[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; ++i) {
      scanf("%*d %*d");
    }
    for (int i = 0; i < n; ++i) {
      p[i] = -1;
      g[i].clear();
    }
    for (int i = 0; i < q; ++i) {
      scanf("%d %d %d", ty+i, a+i, b+i);
      a[i]--; b[i]--;
      if (ty[i] == 1) {
        scanf("%d", c+i);
        if (merge(a[i], b[i])) {
          g[a[i]].emplace_back(b[i], c[i]);
          g[b[i]].emplace_back(a[i], c[i]);
        }
      }
    }
    for (int i = 0; i < n; ++i) if (p[i] < 0) {
      val[i] = 0;
      dfs(i, -1);
    }
    for (int i = 0; i < n; ++i) {
      p[i] = -1;
    }
    for (int i = 0; i < q; ++i) {
      if (ty[i] == 1) {
        merge(a[i], b[i]);
        puts((query(a[i], b[i]) == c[i]) ? "AC" : "WA");
      }
      else {
        printf("%d\n", query(a[i], b[i]));
      }
    }
  }
  return 0;
}