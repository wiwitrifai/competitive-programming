#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

vector<int> g[N];
int id[N];
int used[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u,v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (m == 0) {
    printf("%d\n", n);
    return 0;
  }
  for (int i = 0;i < n; ++i)
    id[i] = i;
  sort(id, id+n, [&](int le, int ri) { return g[le].size() > g[ri].size(); });
  set<int> cliq;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int v = id[i];
    int cnt = 0;
    for (int u : g[v]) {
      cnt += used[u];
    }
    if (cnt == cur) {
      used[v] = 1;
      ++cur;
      cliq.insert(v);
    }
    else if (cnt != g[v].size()) {
      puts("0");
      return 0;
    }
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      if (g[i].size() == cur-1) {
        set<int> st = cliq;
        for (int u : g[i])
          st.erase(u);
        if (st.empty() || g[*st.begin()].size() == cur-1)
          ++ans;
      }
    }
    else if (g[i].size() == cur-1)
      ++ans;
  }
  printf("%d\n", ans);

  return 0;
}