#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e17;
vector< pair< int, int > > g[N];
long long d[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, x, m, s;
    scanf("%d %d %d %d %d", &n, &k, &x, &m, &s);
    s--;
    for (int i = 0; i < n; i++) {
      g[i].clear();
      d[i] = inf;
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--; b--;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    set< pair< long long , int > > st;
    d[s] = 0;
    st.insert(make_pair(d[s], s));
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second;
      st.erase(it);
      for (auto nx : g[v]) {
        int u = nx.first, c = nx.second;
        if (d[u] > d[v] + c) {
          st.erase(make_pair(d[u], u));
          d[u] = d[v] + c;
          st.insert(make_pair(d[u], u));
        }
      }
    }
    long long mi = inf;
    for (int i = 0; i < k; i++)
      mi = min(mi, d[i]);
    mi += x;
    for (int i = 0; i < k; i++) {
      if (d[i] > mi) {
        d[i] = mi;
        st.insert(make_pair(d[i], i));
      }
    }
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second;
      st.erase(it);
      for (auto nx : g[v]) {
        int u = nx.first, c = nx.second;
        if (d[u] > d[v] + c) {
          st.erase(make_pair(d[u], u));
          d[u] = d[v] + c;
          st.insert(make_pair(d[u], u));
        }
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%lld%c", d[i], (i == n-1) ? '\n' : ' ');
    }
  }
  return 0;
}