#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

vector< int > g[N];
int c[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int k = 0;
  set < int > st;
  for (int i = 0; i < n; i++) {
    for (int u : g[i]) if (u < i)
      st.erase(c[u]);
    if (st.empty())
      c[i] = ++k;
    else
      c[i] = *(st.begin());
    for (int u : g[i]) if (u < i)
      st.insert(c[u]);
    st.insert(c[i]);
  }
  printf("%d\n", k);
  for (int i = 0; i < n; ++i) {
    printf("%d ", c[i]);
  }
  printf("\n");

  return 0;
}