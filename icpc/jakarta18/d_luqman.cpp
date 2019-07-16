// By Luqman

#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N][N];
int id[N][N];
vector<int> adj[N * N];
int at[N * N];

void merge(int u, int v) {
  adj[u].push_back(v);
}

vector< int > num, low, S, vis;
int cntr, numCC;

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
    ++numCC;
    // printf("SCC %d :", numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      at[u] = numCC;
      // printf(" %d", u);
      if(u == v)
        break;
    }
    // printf("\n");
  }
}

vector<int> edge[N * N];
int par[N * N];
int to[N * N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void sambung(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for (int i = 0; i < N * N; i++) par[i] = i;

  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      id[i][j] = i * m + j;
    }
  }
  for (int i = 0; i < n; i++) {
    int last = 0;
    for (int j = 0; j < m; j++) {
      merge(id[i][j], id[i][last]);
      if (s[i][j] == '#') {
        last = j;
      }
    }
    last = m - 1;
    for (int j = m - 1; j >= 0; j--) {
      merge(id[i][j], id[i][last]);
      if (s[i][j] == '#') {
        last = j;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    int last = 0;
    for (int i = 0; i < n; i++) {
      merge(id[i][j], id[last][j]);
      if (s[i][j] == '#') {
        last = i;
      }
    }
    last = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      merge(id[i][j], id[last][j]);
      if (s[i][j] == '#') {
        last = i;
      }
    }
  }
  num.assign(n * m, -1);
  low.assign(n * m, 0);
  vis.assign(n * m, 0);
  cntr = numCC = 0;
  for(int i = 0; i<n*m; i++)
    if(num[i] == -1)
      tarjanSCC(i);

  set<pair<int, int>> wow;
  for (int i = 0; i < n * m; i++) {
    for (auto it : adj[i]) {
      int u = at[i];
      int v = at[it];
      if (!wow.count(make_pair(u, v)) && u != v) {
        // printf("%d %d\n", u, v);
        edge[u].push_back(v);
        to[v]++;
        wow.insert(make_pair(u, v));
      }
    }
  }
  queue<int> q;
  for (int i = 1; i <= numCC; i++) {
    if (to[i] == 0) {
      q.push(i);
    }
  }
  int ans = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    // printf("process %d\n", now);
    bool flip = 0;
    for (auto it : edge[now]) {
      if (find(now) != find(it)) {
        flip = 1;
        break;
      }
    }
    if (flip) {
      ans++;
      for (auto it : edge[now]) {
        sambung(now, it);
      }
    }
    for (auto it : edge[now]) {
      to[it]--;
      if (to[it] == 0) {
        q.push(it);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
