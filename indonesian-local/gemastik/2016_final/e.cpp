#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector< int > adj[N];
int cnt, lim;
pair<int, int> dfs(int v, int p = -1) {
  pair < int, int> ret = {0, 0};
  int a = 0, b = -1;
  for (int u : adj[v]) if (u != p) {
    auto res = dfs(u, v);
    if (res.first < 0)
      b = max(res.second-1, b);
    else
      a = max(res.first+1, a);
  }
  if (a <= b) {
    return make_pair(-1, b);
  }
  if (a >= lim || !v) {
    cnt++;
    return make_pair(-1, lim);
  }
  return make_pair(a, 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
      adj[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int l = 0, r = n;
    while (l < r) {
      lim = (l+r) >> 1;
      cnt = 0;
      dfs(0);
      if (cnt <= k)
        r = lim;
      else
        l = lim+1;
    }
    printf("%d\n", l);
  }
  return 0;
}