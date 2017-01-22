#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > adj[N];
int p[N];
set< pair<int, int> > st;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    st.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", p+i);
      st.insert(make_pair(-p[i], i));
      adj[i].clear();
      adj[i].push_back(i);
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
      for (int u : adj[i])
        st.erase(make_pair(-p[u], u));
      printf("%d ", st.empty() ? 0 : st.begin()->second + 1);
      for (int u : adj[i])
        st.insert(make_pair(-p[u], u));
    }
    printf("\n");
  }
  return 0;
}