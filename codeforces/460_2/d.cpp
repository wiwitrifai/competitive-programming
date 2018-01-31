#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
vector<int> g[N];
int din[N];
int dp[N][26];
char s[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) s[i] -= 'a';
  bool ok = 1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    if (u == v)
      ok = 0;
    ++din[v];
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  stack<int> st;
  vector<int> topo;
  for (int i = 0; i < n; ++i) {
    if (din[i] == 0)
      st.push(i);
  }
  while (!st.empty()) {
    int v = st.top(); st.pop();
    topo.push_back(v);
    for (int u : g[v]) {
      --din[u];
      if (din[u] == 0)
        st.push(u);
    }
  }
  if (topo.size() != n)
    puts("-1");
  else {
    int ans = 0; 
    for (int i = n-1; i >= 0; --i) {
      int v = topo[i];
      for (int u : g[v]) {
        for (int j = 0; j < 26; ++j)
          dp[v][j] = max(dp[v][j], dp[u][j]);
      }
      ++dp[v][s[v]];
      ans = max(ans, dp[v][s[v]]);
    }
    printf("%d\n", ans);
  }
  return 0;
}