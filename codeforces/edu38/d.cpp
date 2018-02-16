#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair<int, long long> > g[N];
long long ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    long long w;
    scanf("%d %d %I64d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  set<pair<long long, int> > st;
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", ans+i);
    st.insert(make_pair(ans[i], i));
  }
  while (!st.empty()) {
    auto it = st.begin();
    int v = it->second; st.erase(it);
    for (auto nx : g[v]) {
      long long nval = ans[v] + nx.second * 2;
      int u = nx.first;
      if (ans[u] > nval) {
        st.erase(make_pair(ans[u], u));
        ans[u] = nval;
        st.insert(make_pair(ans[u], u));
      }
    }
  }
  for (int i = 0; i < n; ++i)
    printf("%I64d%c", ans[i], (i == n-1) ? '\n' : ' ');
  return 0;
}