#include <bits/stdc++.h>

using namespace std;

const int N = 2525, NLOG = 13;

int a[N][N];
pair< int, int > id[N*N];
int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int u, int v) {
  if((u = find(u)) == (v = find(v)))
    return false;
  if(p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}
vector< int > adj[N];
int em[N][NLOG], par[N][NLOG], lv[N];

void dfs(int v, int p = -1) {
  if(p != -1) {
    lv[v] = lv[p] + 1;
    par[v][0] = p;
    em[v][0] = a[v][p];
    for(int i = 0; i<NLOG-1; i++) if(par[v][i] != -1) {
      par[v][i+1] = par[par[v][i]][i];
      em[v][i+1] = max(em[v][i], em[par[v][i]][i]);
    }
  }
  else
    lv[v] = 0;
  for(auto u : adj[v]) if(u != p) {
    dfs(u, v);
  }
}

int get(int u, int v) {
  if(lv[u] < lv[v])
    swap(u, v);
  int ret = 0;
  int dif = lv[u] - lv[v];
  for(int i = 0; i < NLOG; i++) if(dif & (1<<i)) {
    ret = max(ret, em[u][i]);
    u = par[u][i];
  }
  if(u == v)
    return ret;
  for(int i = NLOG-1; i>=0; i--)
    if(par[u][i] != par[v][i]) {
      ret = max(ret, max(em[v][i], em[u][i]));
      u = par[u][i];
      v = par[v][i];
    }
  return max(ret, max(em[v][0], em[u][0]));
}

int main() {
  int n, m = 0;;
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++) {
      scanf("%d", a[i]+j);
    }
  bool magic = true;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j<i; j++) {
      if(a[i][j] != a[j][i])
        magic = false;
      id[m++] = make_pair(i, j);
    }
    if(a[i][i] != 0)
      magic = false;
  }
  if(!magic) {
    puts("NOT MAGIC");
    return 0;
  }
  sort(id, id + m, [](pair<int, int> pp, pair<int, int> qq) { return a[pp.first][pp.second] < a[qq.first][qq.second]; });
  int cnt = 0;
  memset(p, -1, sizeof p);
  for(int i = 0; i<m; i++) {
    if(cnt == n-1)
      break;
    if(merge(id[i].first, id[i].second)) {
      cnt++;
      adj[id[i].first].push_back(id[i].second);
      adj[id[i].second].push_back(id[i].first);
    }
  }
  memset(par, -1, sizeof par);
  dfs(0);
  for(int i = 0; i<n && magic; i++) {
    for(int j  = 0; j<i && magic; j++)
      if(a[i][j] != get(i, j)) {
        magic = false;
      }
  }
  puts(magic ? "MAGIC" : "NOT MAGIC");
  return 0;
}