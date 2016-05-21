#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector< pair< int, int > > adj[N], to[N];
stack< int > st;
int p[N], num[N], low[N], n, m, c_num, com[N], ncom, val[N], b;

void scc(int v = 0) {
  num[v] = low[v] = ++c_num;
  st.push(v);
  for(auto nx : adj[v]) {
    if(num[nx.first] == -1) {
      p[nx.first] = v;
      scc(nx.first);
      if(low[nx.first] > num[v]) {
        while(!st.empty()) {
          int u = st.top();
          com[u] = ncom;
          st.pop();
          if(nx.first == u)
            break;  
        }
        ncom++;
      }
      low[v] = min(low[v], low[nx.first]);
    }
    else if(nx.first != p[v])
      low[v] = min(low[v], low[nx.first]);
  }
}

bool dfs(int v = 0, int par = -1, int value = 0) {
  if(val[v])
    value = 1;
  if(v == b)
    return value;
  for(auto nx : to[v]) if(nx.first != par) {
    if(dfs(nx.first, v, value | nx.second))
      return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++) {
    int u, v, z;
    scanf("%d%d%d", &u, &v, &z);
    u--; v--;
    adj[u].emplace_back(v, z);
    adj[v].emplace_back(u, z);
  }
  ncom = 0;
  memset(p, -1, sizeof p);
  memset(num, -1, sizeof num);
  scc();
  while(!st.empty()) {
    com[st.top()] = ncom;
    st.pop();
  }
  for(int i = 0; i<n; i++) {
    for(auto nx : adj[i]) if(com[nx.first] != com[i])
      to[com[i]].emplace_back(com[nx.first], nx.second);
    else 
      if(nx.second)
        val[com[i]] = 1;
  }
  int a;

  scanf("%d%d", &a, &b);
  a--; b--;
  a = com[a];
  b = com[b];
  puts(dfs(a) ? "YES" : "NO");
  return 0;
}