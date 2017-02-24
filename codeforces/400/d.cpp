#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector< int > adj[N];
int r[N];
vector< int > saklar[N];

void add(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int low[N], num[N], cntr, vis[N], com[N], ncom;
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
    while(S.size() > 0) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      com[u] = ncom;
      if(u == v)
        break;
    }
    ncom++;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", r+i);
  }
  for (int i = 0; i < m; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      x--;
      saklar[x].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    int u = saklar[i][0], v = saklar[i][1];
    if (r[i] == 0) {
      add(u+m, v);
      add(u, v+m);
    }
    else {
      add(u+m, v+m);
      add(u, v);
    }
  }
  ncom = 0;
  cntr = 0;
  memset(low, -1, sizeof low);
  memset(num, -1, sizeof num);
  memset(vis, 0, sizeof vis);
  for (int i = 0;i < 2 * m; i++) if (num[i] == -1) {
    tarjanSCC(i);
  }
  bool ok = 1;
  for (int i = 0; i < m; i++) {
    if (com[i] == com[i+m])
      ok = 0;
  }
  puts(ok ? "YES" : "NO");

  return 0;
}