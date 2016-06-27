#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector< pair<int, int> > adj[N];
int n, m, p[N], d[N];
pair< int, pair<int, int> > q[N];
void dfs(int v, int par = -1) {
  for(auto it : adj[v]) if(it.first != par) {
    p[it.first] = v;
    d[it.first] = it.second;
    dfs(it.first, v);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++)
      adj[i].clear();
    for(int i = 1; i<n; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      a--; b--;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
    }
    for(int i = 0; i<m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      q[i] = {c, {a-1, b-1}};
    }
    dfs(0);
    sort(q, q+m);
    long long ans = 0;
    for(int i = m-1; i>=0; i--) {
      int now = q[i].second.second, to = q[i].second.first;
      bool ok = true;
      while(now != to) {
        if(d[now] == 0)
          ok = false;
        now = p[now];
      }
      if(!ok)
        continue;
      now = q[i].second.second;
      while(now != to) {
        d[now]--;
        now = p[now];
      }
      ans += q[i].first;
    }
    printf("%lld\n", ans);
  }
  

  return 0;
}