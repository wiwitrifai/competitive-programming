#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;

vector< int > g[N];
bool vis[N], used[N];
vector < int > step[N];
vector < int >  st;
int n, m, k, s, cur = -1;
void dfs(int u) {
  vis[u] = 1;
  for (int v : g[u]) if (!vis[v]) {
    if (cur != -1 && step[cur].back() != u) {
      step[cur].push_back(u);
      used[u] = 1;
      if (step[cur].size() >= s) {
        cur = -1;
      }
    }
    dfs(v);
  }
  if (cur == -1 && !used[u]) {
    cur = u;
    st.push_back(u);
    step[cur].push_back(u);
    used[u] = 1;
  }
  if (cur != -1 && step[cur].back() != u) {
    step[cur].push_back(u);
    used[u] = 1;
    if (step[cur].size() >= s)
      cur = -1;
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    if (u == v) continue;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(vis, 0, sizeof vis);
  memset(used, 0, sizeof used);
  cur = -1;
  s = (2 * n + k - 1) / k;
  for (int i = 0; i < n; i++) if (!vis[i]) {
    dfs(i);
  }
  for (int i = 0; i < k; i++) {
    if (i >= st.size())
      printf("1 1\n");
    else {
      int now = st[i];
      printf("%d", step[now].size());
      for (int u : step[now])
        printf(" %d", u + 1);
      printf("\n");
    }
  }
  return 0;
}