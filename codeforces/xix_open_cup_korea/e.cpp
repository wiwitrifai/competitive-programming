#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

set<int> g[N];
set<pair<int, int> > sz;

void add_edge(int u, int v, int w) {
  sz.erase(make_pair(g[u].size(), u));
  sz.erase(make_pair(g[v].size(), v));
  g[u].insert(v);
  g[v].insert(u);
  g[u].erase(w);
  g[v].erase(w);
  sz.insert(make_pair(g[u].size(), u));
  sz.insert(make_pair(g[v].size(), v));
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].insert(v);
    g[v].insert(u);
  }
  for (int i = 1; i <= n; ++i)
    if (g[i].size() >= 2)
      sz.insert(make_pair(g[i].size(), i));
  while (!sz.empty()) {
    auto it = sz.begin();
    if (it->first > 2)
      break;
    int v = it->second;
    sz.erase(it);
    if (g[v].size() < 2)
      continue;
    auto a = g[v].begin(), b = a;
    ++b;
    add_edge(*a, *b, v);
    g[v].clear();
  }
  int one = 0, more = 0;
  for (int i = 1; i <= n; ++i) {
    if (g[i].empty()) continue;
    if (g[i].size() == 1)
      ++one;
    else if (g[i].size() == 2)
      assert(false);
    else {
      ++more;
    }
  }
  if (one > 2 || more > 0) {
    puts("No");
  }
  else
    puts("Yes");
  return 0;
}
