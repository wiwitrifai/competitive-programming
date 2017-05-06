#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector< int > g[N], s[N];
int c[N], n, m;
set< int > st;
void dfs(int v, int par= -1) {
  for (int x : s[v]) if (c[x])
    st.erase(c[x]);
  for (int x : s[v]) if (c[x] == 0) {
    auto it = st.begin();
    c[x] = *it;
    st.erase(it);
  }
  for (int x : s[v])
    st.insert(c[x]);
  assert(st.size() == m);
  for (int u : g[v]) if (u != par)
    dfs(u, v);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    for (int j = 0; j < v; j++) {
      int x;
      scanf("%d", &x); x--;
      s[i].push_back(x);
    }
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int root = 0;
  for (int i = 0; i < n; i++) if (s[i] > s[root]) root = i;
  for (int i = 0; i < m; i++)
    st.insert(i+1);
  dfs(root);
  int k = 0;
  for (int i = 0; i < m; i++) {
    if (c[i] == 0) c[i] = 1;
    k = max(k, c[i]);
  }
  printf("%d\n", k);
  for (int i = 0; i < m; i++) {
    printf("%d ", c[i]);
    assert(c[i] >= 1 && c[i] <= k);
  }
  printf("\n");
  return 0;
}