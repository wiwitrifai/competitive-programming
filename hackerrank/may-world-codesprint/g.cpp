#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 18;

int n, m, q, tm_stmp;
pair< int, pair<int, int> > ed[N];
vector< pair<int, int> > adj[N];
int st[N], seq[N], c[N], p[N], par[M][N], lv[N], pos[N], up[N];
vector< pair< int, int > > que;
vector< int > val[N];

int bit[N];
void upd(int x, int v) {
  x++;
  for(; x; x-= x&(-x))
    bit[x] += v;
}
int get(int x) {
  x++; int ret = 0;
  for(; x<=n; x += x&(-x))
    ret += bit[x];
  return ret;
}

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v, int w) {
  if((u = find(u)) == (v = find(v)))
    return false;
  if(p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  up[u] = w;
  adj[v].push_back(make_pair(w, u));
  // cerr << u << "->"<< v << endl;
  return true;
}

void dfs(int v) {
  seq[tm_stmp] = v;
  st[v] = tm_stmp++;
  for(int i = 0; i+1<M; i++)
    if(par[i][v] >= 0)
      par[i+1][v] = par[i][par[i][v]];
  for(auto it : adj[v]) {
    par[0][it.second] = v;
    lv[it.second] = lv[v] + 1;
    dfs(it.second);
    que.emplace_back(tm_stmp-1, v);
  }
}
int ans;
int lca(int x, int y) {
  if(lv[x] < lv[y])
    swap(x, y);
  int diff = lv[x] - lv[y];
  if(diff) {
    diff--;
    for(int i = 0; i<M; i++)
      if(diff & (1<<i))
        x = par[i][x];
    ans = max(ans, up[x]);
    x = par[0][x];
  }
  if(x == y)
    return x;
  for(int i = M-1; i>=0; i--)
    if(par[i][x] != par[i][y])
      x = par[i][x], y = par[i][y];
  ans = max(ans, max(up[x], up[y]));
  return par[0][x];
}

vector< int > compress;

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 0; i<n; i++) {
    scanf("%d", c+i);
    compress.push_back(c[i]);
  }
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  for(int i = 0; i<n; i++) {
    c[i] = lower_bound(compress.begin(), compress.end(), c[i]) - compress.begin();
  }
  for(int i = 0; i<m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w); u--;v--;
    ed[i] = make_pair(w, make_pair(u, v));
  }
  sort(ed, ed + m);
  memset(p, -1, sizeof p);
  for(int i = 0; i<m; i++)
    merge(ed[i].second.first, ed[i].second.second, ed[i].first); 
  tm_stmp = 0;
  memset(par, -1, sizeof par);
  for(int i = 0; i<n; i++) if(p[i] < 0) {
    lv[i] = 0;
    dfs(i);
  }
  assert(tm_stmp == n);
  sort(que.begin(), que.end());
  int id = 0;
  memset(pos, -1, sizeof pos);
  for(int i = 0; i<n; i++) {
    int col = c[seq[i]];
    if(pos[col] >= 0)
      upd(pos[col], -1);
    pos[col] = i;
    upd(i, 1);
    while(id < que.size() && que[id].first <= i) {
      int l = que[id].second;
      val[l].push_back(get(st[l]));
      id++;
    }
  }
  for(int i = 0; i<n; i++)
    assert(adj[i].size() == val[i].size());
  assert(id == que.size());
  while(q--) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    x--; y--;
    if(x == y && w <= 1) {
      puts("0");
      continue;
    }
    if(find(x) != find(y)) {
      puts("-1");
      continue;
    }
    ans = 0;
    int v = lca(x, y);
    if(v == -1) {
      puts("-1");
      continue;
    }
    if(val[v].empty() || val[v].back() < w) {
      for(int i = M-1; i>=0; i--) if(par[i][v] > -1 && (val[par[i][v]].empty() || val[par[i][v]].back() < w))
        v = par[i][v];
      ans = max(ans, up[v]);
      v = par[0][v];
      if(v == -1 || val[v].empty() || val[v].back() < w) {
        puts("-1");
        continue;
      }
    }
    x = upper_bound(val[v].begin(), val[v].end(), w-1) - val[v].begin();
    if(x >= val[v].size() || val[v][x] < w) {
      puts("-1");
      continue;
    }
    // cerr << v << " v"<< endl;
    ans = max(ans, adj[v][x].first);
    printf("%d\n", ans);
  }
  return 0;
}