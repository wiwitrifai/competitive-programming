#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int val[N], p[N];
int c[N];
bool up[N];
void dfs(int v) {
  val[v] = c[v];
  for (int u : g[v]) if (u != p[v]) {
    p[u] = v;
    dfs(u);
    if (up[u])
      val[v] += val[u];
  }
  up[v] = val[v] > 0;
}

vector<int> vans;

void get(int v) {
  vans.push_back(v+1);
  for (int u : g[v]) if (u != p[v] && up[u])
    get(u);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", c+i);
    if (c[i] == 0)
      c[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0, vv = -1;
  dfs(0);
  for (int i = 0; i < n; i++) {
    if (ans < val[i]) {
      ans = val[i];
      vv = i;
    }
  }
  if (vv != -1) {
    vans.clear();
    get(vv);
  }
  for (int i = 0; i < n; i++)
    c[i] *= -1;
  vv = -1;
  dfs(0);
  for (int i = 0; i < n; i++) {
    if (ans < val[i]) {
      ans = val[i];
      vv = i;
    }
  }
  if (vv != -1) {
    vans.clear();
    get(vv);
  }
  printf("%d\n", ans);
  printf("%d\n", vans.size());
  sort(vans.begin(), vans.end());
  for (int i = 0; i < vans.size(); i++) {
    printf("%d%c", vans[i], (i+1) == vans.size() ? '\n' : ' ');
  }
  return 0;
}