#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, LN = 20;

vector< int > g[N], tree[N];
int d[N], n, m, a[N], b[N], vis[N], used[N], val[N];
vector< int > one, mone;
void dfs(int v, int par) {
  vis[v] = 1;
  if (d[v] == -1)
    mone.push_back(v);
  else if (d[v] == 1)
    one.push_back(v);
  for (int i : g[v]) {
    int u = a[i] ^ b[i] ^ v;
    if (!vis[u]) {
      tree[v].push_back(i);
      dfs(u, v);
    }
  }
}

void proc(int u, int v) {
  val[u] ^= 1;
  val[v] ^= 1;
}
void solve(int v) {
  for (int i : tree[v]) {
    int u = a[i] ^ b[i] ^ v;
    solve(u);
    used[i] = val[u];
    val[v] ^= val[u];
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", d+i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", a+i, b+i);
    a[i]--; b[i]--;
    g[a[i]].push_back(i);
    g[b[i]].push_back(i);
  }
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++) if (!vis[i]) {
    one.clear();
    mone.clear();
    dfs(i, i);
    if (one.size() & 1) {
      if (mone.size() == 0) {
        puts("-1");
        return 0;
      }
      one.push_back(mone.back());
    }
    for (int j = 0; j < one.size(); j += 2)
      proc(one[j], one[j+1]);
    solve(i);
  }
  int cnt = 0;
  for (int i = 0; i < m; i++)
    cnt += used[i];
  printf("%d\n", cnt);
  for (int i = 0; i < m; i++)
    if (used[i])
      printf("%d\n", i+1);
  return 0;
}