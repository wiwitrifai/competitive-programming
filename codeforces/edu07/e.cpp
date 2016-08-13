#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector < int > adj[N];
int n;
vector< int > t;
void dfs(int u, int lv = 0, int p = -1) {
  if (adj[u].size() == 1)
    t.push_back(lv);
  for (int v : adj[u]) if (v != p) {
    dfs(v, lv+1, u);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  for (int u : adj[0]) {
    t.clear();
    dfs(u, 1, 0);
    sort(t.begin(), t.end());
    int now = 0;
    for (int i = 0; i < t.size(); i++) {
      now = max(now+1, t[i]);
    }
    t.clear();
    ans = max(ans, now);
  }
  printf("%d\n", ans);


  return 0;
}