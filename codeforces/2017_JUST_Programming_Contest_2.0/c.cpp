#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, inf = 1e9 + 7;
vector< int > g[N];
int val[N], d[N];
char s[N];
int main() {
  int n, m, from = -1, to = -1;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    val[i] = 0;
    for (int j = 0; j < len; j++) {
      char c = s[j];
      int now = -1;
      if (c <= 'z' && c >= 'a')
        now = c-'a';
      else
        now = c-'A';
      val[i] |= 1<<now;
    }
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%d %d", &from, &to);
  from--; to--;
  for (int i = 0; i < n; i++)
    d[i] = inf;
  set< pair< int, int > > st;
  d[from] = 0;
  st.insert(make_pair(0, from));
  while (!st.empty()) {
    auto it = st.begin();
    int now = it->second;
    st.erase(it);
    for (int u : g[now]) {
      int cost = __builtin_popcount(val[u] & val[now]);
      if (d[u] > d[now] + cost) {
        st.erase(make_pair(d[u], u));
        d[u] = d[now] + cost;
        st.insert(make_pair(d[u], u));
      }
    }
  }
  printf("%d\n", d[to]);
  return 0;
}