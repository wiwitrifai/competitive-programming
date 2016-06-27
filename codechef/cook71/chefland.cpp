#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector< int > adj[N];
int n, m;
int num[N], low[N], cnt, now, com[N], deg[N];
stack< int > st;

void dfs(int v, int par = -1) {
  num[v] = low[v] = now++;
  st.push(v);
  int parc = 0;
  for(int u : adj[v]) {
    if(u == par && parc == 0) {
      parc++;
      continue;
    }
    if(num[u] == -1) {
      dfs(u, v);
      low[v] = min(low[v], low[u]);
    }
    else {
      low[v] = min(low[v], num[u]);
    }
  }
  if(num[v] == low[v]) {
    // cerr << v << endl;
    while(!st.empty()) {
      int u = st.top();
      com[u] = cnt;
      st.pop();
      if(u == v)
        break;
    }
    cnt++;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  now = cnt = 0;
  bool ok = true;
  memset(num, -1, sizeof num);
  dfs(0);
  // for(int i = 1; i<n; i++) if(num[i] == -1)
  //     ok = false;
  set< pair<int, int > > ss;
  for(int i = 0; i<n; i++) {
    for(int u : adj[i]) if(com[u] != com[i] && !ss.count({com[u], com[i]})) {
      deg[com[u]]++;
      deg[com[i]]++;
      ss.insert({com[u], com[i]});
      ss.insert({com[i], com[u]});
    }
  }
  int one = 0, two = 0;
  for(int i = 0; i<cnt; i++) {
    // cerr << i << " " << deg[i] << endl;
    if(deg[i] > 2)
      ok = false;
  }
  puts(ok ? "YES" : "NO");
  return 0;
}