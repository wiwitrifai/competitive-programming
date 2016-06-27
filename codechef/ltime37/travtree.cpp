#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int NLOG = 19;

struct fen {
  vector< int > bit;
  int n;
  fen(int n) : n(n) {
    bit.assign(n+1, 0);
  }
  int get(int x) {
    int ret = 0;
    for(; x<=n; x += x & (-x))
      ret += bit[x];
    return ret;
  }
  void add(int x, int v) {
    for(; x; x-= x&(-x))
      bit[x] += v;
  }
};
int n, com[N], pos[N], sz[N], ncom, cnt[N], par[NLOG][N], lv[N], mv[N], head[N];
fen * up[N], * down[N];
vector<int> adj[N];

void getsz(int v, int p= -1) {
  sz[v] = 1;
  par[0][v] = p;
  lv[v] = (p == -1) ? 0 : lv[p] + 1;
  for(int i = 0; i+1<NLOG; i++) {
    if(par[i][v] != -1)
      par[i+1][v] = par[i][par[i][v]];
    else
      break;
  }
  for(int u : adj[v]) if(u != p) {
    getsz(u, v);
    sz[v] += sz[u];
  }
}


void dec_hld(int v, int p = -1) {
  com[v] = ncom;
  pos[v] = cnt[ncom]++;
  int bg = -1, bsz = -1;
  for(int u : adj[v]) if(u != p) {
    if(bsz < sz[u]) {
      bg = u;
      bsz = sz[u];
    }
  }
  if(bg != -1) {
    dec_hld(bg, v);
  }
  for(int u: adj[v]) if(u != p && u != bg) {
    ncom++;
    cnt[ncom] = 0;
    head[ncom] = v;
    dec_hld(u, v);
  }
}
int lca(int u, int v) {
  if(lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for(int i = NLOG-1; i>=0; i--)
    if(diff & (1<<i))
      v = par[i][v];
  if(u == v)
    return u;
  for(int i = NLOG-1; i>=0; i--)
    if(par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  return par[0][v];
}

int solve(int u, int v) {
  int w = lca(u, v);
  int ans = 0, bu = -1, bv = -1;
  // cerr << u << " " << v << ' ' << w << endl;
  // cerr << com[u] << " " << com[v] << " " << com[w] << endl;
  while(com[u] != com[w]) {
    int now = com[u];
    ans += down[now]->get(1) - down[now]->get(pos[u]+2);
    up[now]->add(pos[u]+1, 1);
    bu = u;
    u = head[now];
  }
  while(com[v] != com[w]) {
    int now = com[v];
    ans += down[now]->get(1) - down[now]->get(pos[v]+2);
    up[now]->add(pos[v]+1, 1);
    bv = v;
    v = head[now];
    // cerr << ans << " " << v << " " << bv << endl;
  }
  int now = com[w];
  if(pos[u] < pos[v]) {
    swap(u, v);
    swap(bu, bv);
  }
  ans += up[now]->get(pos[w]+1) - down[now]->get(pos[u]+2);
  up[now]->add(pos[u]+1, 1);
  down[now]->add(pos[w]+1, 1);
  // cerr << pos[u] << " " << pos[w] << " " << pos[u] << endl;
  // cerr << ans << endl;
  return ans; 
}

int main() {
  memset(par, -1, sizeof par);
  scanf("%d", &n);
  for(int i = 1; i<n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }
  int q;
  scanf("%d", &q);
  ncom = 0;
  getsz(0);
  dec_hld(0);
  for(int i = 0; i<=ncom; i++) {
    up[i] = new fen(cnt[i]+1);
    down[i] = new fen(cnt[i]+1);
  }
  // cerr << "query" << endl;
  while(q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    int res = solve(--u, --v);
    printf("%d\n", res);
  }
  return 0;
}