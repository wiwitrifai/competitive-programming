#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector< int > adj[N], e[N];
int a[N], b[N], m;
int v[N];
void add2(int x, int y) {
  adj[x].push_back(m-y);
  adj[y].push_back(m-x);
}
void add3(int x, int y, int z) {
  add2(x, m-y);
  add2(x, m-z);
  add2(y, m-x);
  add2(y, m-z);
  add2(z, m-x);
  add2(z, m-y);
}
int com[N];

int num[N], low[N], vis[N];
int cntr, numCC;
vector< int > S;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      com[u] = numCC;
      if(u == v)
        break;
    }
    numCC++;
  }
}

int col[N], to[N];
vector< int > g[N];


int main() {
  int n;
  scanf("%d", &n);
  m = 2 * n - 1;
  for (int i= 0; i < n; i++) {
    scanf("%d %d", a+i, b+i);
    a[i]--; b[i]--;
    v[a[i]] = i;
    v[b[i]] = m - i;
  }
  add3(v[2 * n - 2], v[2 * n - 1], v[0]);
  add3(v[2 * n - 1], v[0], v[1]);
  for (int i = 2; i <= m; i++) {
    add3(v[i-2], v[i-1], v[i]);
  }
  for (int i = 0; i <= m; i++) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    for (int u : adj[i])
      cerr << i << "->" << u << endl;
  }
  memset(num, -1, sizeof num);
  memset(low, 0, sizeof low);
  memset(vis, 0, sizeof vis);
  cntr = numCC = 0;
  for (int i = 0; i <= m; i++) if (num[i] == -1)
    tarjanSCC(i);
  for (int i = 0; i < n; i++) {
    if (com[i] != com[m-i]) {
      puts("-1");
      return 0;
    }
  }
  memset(to, 0, sizeof to);
  for (int i = 0; i <= m; i++) {
    for (int u : adj[i]) if (com[u] != com[i]) {
      g[com[i]].push_back(com[u]);
      to[com[u]]++;
    }
    e[com[i]].push_back(i);
  }
  memset(col, -1, sizeof col);
  stack < int > st;
  for (int i = 0; i < numCC; i++) {
    if (to[i] == 0)
      st.push(i);
  }
  while (!st.empty()) {
    int u = st.top(); st.pop();
    if (col[u] == -1) {
      col[u] = 0;
    }
    for (int v : e[u]) {
      col[com[m-v]] = 1- col[u];
    }
    for (int v : g[u]) {
      to[v]--;
      if (to[v] == 0)
        st.push(v);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", col[i] + 1, col[m-i] + 1);
  }
  return 0;
}