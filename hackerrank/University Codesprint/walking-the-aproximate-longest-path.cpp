#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, BOMB = 500;

int n, m;
vector< int > adj[N];
int com[N], ncom, vis[N], low[N], cntr, sz[N];
vector< pair<int, pair<int, int> > > g[N];
stack< int > st;

void dfs(int v, int p) {
  st.push(v);
  low[v] = vis[v] = cntr++;
  for (int u : adj[v]) if (p != u) {
    if (vis[u] == -1)
      dfs(u, v);
    low[v] = min(low[u], low[v]);
  }
  if (low[v] == vis[v]) {
    sz[ncom] = 0;
    while (1) {
      sz[ncom]++;
      int u = st.top();
      com[u] = ncom;
      st.pop();
      if (u == v)
        break;
    }
    ncom++;
  }
}

vector< int > preq;
vector< int > best, tmp, ans;
void dfs2(int v, int p = -1) {
  for (auto u : g[v]) if (u.first != p) {
    preq.push_back(u.second.first);
    preq.push_back(u.second.second);
    dfs2(u.first, v);
  }
}
int bomb;
void dfs3(int v) {
  vis[v] = 1;
  tmp.push_back(v);
  bomb--;
  if (bomb < 0) {
    if (best.size() < tmp.size()) 
      best = tmp;
    vis[v] = 0;
    tmp.pop_back();
    return;
  }
  for (int u : adj[v]) if (!vis[u]) {
    dfs3(u);
    if (bomb < 0) {
      vis[v] = 0;
      tmp.pop_back();
      return;
    }
  }
  if (best.size() < tmp.size())
    best = tmp;
  tmp.pop_back();
  vis[v] = 0;
}
void dfs4(int v, int t) {
  vis[v] = 1;
  tmp.push_back(v);
  bomb--;
  if (v == t) {
    if (best.size() < tmp.size()) {
      best = tmp;
    }
    vis[v] = 0;
    tmp.pop_back();
    return;
  }
  if (bomb < 0) {
    vis[v] = 0;
    tmp.pop_back();
    return;
  }
  for (int u : adj[v]) if (!vis[u]) {
    dfs4(u, t);
  } 
  vis[v] = 0;
  tmp.pop_back();
}

int main() {
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  for (int i = 0; i <m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    random_shuffle(adj[i].begin(), adj[i].end());
  }
  ncom = 0;
  cntr = 0;
  dfs(1, -1);
  int stcom = 0;
  for (int i = 1; i <= n; i++) {
    for (int u : adj[i]) if (com[i] != com[u]) {
      g[com[i]].push_back({com[u], {i, u}});
    }
  }
  for (int i = 0; i < ncom; i++) if (g[i].size() < g[stcom].size())
    stcom = i;
  dfs2(stcom);
  memset(vis, 0, sizeof vis);
  if (preq.size()) {
    vis[preq[1]] = 1;
    tmp.clear(); best.clear();
    bomb = BOMB * sz[stcom];
    dfs3(preq[0]);
    reverse(best.begin(), best.end());
    ans.insert(ans.end(), best.begin(), best.end()); 
    vis[preq[1]] = 0;
    vis[preq[0]] = 1;
    bool ok = true;
    for (int i = 2; i < preq.size(); i+=2) {
      if (preq[i] == preq[i-1])
        ans.push_back(preq[i]);
      else {
        tmp.clear(); best.clear(); bomb = sz[com[preq[i]]] * BOMB;
        dfs4(preq[i-1], preq[i]);
        ok &= (best.size() > 0);
        ans.insert(ans.end(), best.begin(), best.end());
        if (!ok) {
          tmp.clear(); best.clear(); bomb = sz[com[preq[i]]] * BOMB;
          dfs3(preq[i-1]);
          ans.insert(ans.end(), best.begin(), best.end());
          break;
        }
      }
    }
    if (ok) {
      tmp.clear(); best.clear(); bomb = sz[com[preq.back()]] * BOMB;
      dfs3(preq.back());
      ans.insert(ans.end(), best.begin(), best.end());      
    }
  }
  else {
    for (int i = 0; i < 10; i++) {
      bomb = BOMB * n / 10;
      dfs3((rand() % n) + 1);
    }
    ans = best;
  }
  printf("%d\n", ans.size());
  for (int v : ans)
    printf("%d ", v);
  printf("\n");

  return 0;
}