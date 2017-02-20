#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > g[N];
set< int > * st[N];
set< int > up;
int n, cnt[N], sz[N], ans[N];
void gs(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) if (u != par) {
    gs(u, v);
    sz[v] += sz[u];
  }
}
void add(int id, int val) {
  if (cnt[id] == 0)
    up.insert(id);
  cnt[id] += val;
  if (cnt[id] == 0)
    up.erase(id);
}

void push(int v, int par, int val) {
  add(sz[v], val);
  for (int u : g[v]) if (u != par)
    push(u, v, val);
}
void push2(int v, int par, set< int > *ss) {
  ss->insert(sz[v]);
  for (int u : g[v]) if (u != par)
    push2(u, v, ss);
}

void dfs(int v, int par = -1) {
  cerr << v << " " << par << endl;
  int bg = -1;
  for (int u : g[v]) if (u != par) {
    if (bg == -1 || sz[u] > sz[bg])
      bg = u;
  } 
  if (bg != -1)
    push(bg, v, +1);
  for (int u : g[v]) if (u != par && u != bg) {
    push(u, v, +1);
  }
  for (int u : g[v]) if (u != par && u != bg) {
    push(u, v, -1);
    dfs(v, par);
    push(u, v, +1);
  }
  if (bg == -1)
    st[v] = new set<int>();
  else {
    push(bg, v, -1);
    dfs(bg, v);
    st[v] = st[bg];
  }
  vector< int > vs;
  if (par != -1)
    vs.push_back(n-sz[v]);
  for (int u : g[v]) if (u != par)
    vs.push_back(sz[u]);
  if (vs.size() == 0)
    ans[v] = 0;
  else if (vs.size() == 1)
    ans[v] = vs[0];
  else {
    sort(vs.begin(), vs.end());
    int ma = vs[(int)vs.size() - 2];
    if (bg != -1 && vs.back() == sz[bg]) {
      auto it = st[v]->lower_bound((sz[bg]-vs[0])/2);
      int now = ma;
      if (it !=st[v]->end())
        now = max(now, max(vs[0] + *it, sz[bg] - *it));
      if (it != st[v]->begin()) {
        it--;
        now = min(now, max(ma, max(vs[0]+*it, sz[bg]-*it)));
      }
      ans[v] = now;
    }
    else {
      int ss = n-sz[v];
      auto it = up.lower_bound((ss-vs[0])/2);
      int now = ma;
      if (it !=up.end())
        now = max(now, max(vs[0] + *it, ss - *it));
      if (it != up.begin()) {
        it--;
        now = min(now, max(ma, max(vs[0]+*it, ss-*it)));
      }
      ans[v] = now;
    }
    if (bg != -1)
      st[v]->insert(sz[bg]);
    for (int u : g[v]) if (u != par && u != bg) {
      push2(u, v, st[v]);
      push(u, v, -1);
    }
  }
}


int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u,&v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  gs(0);
  dfs(0);
  for (int i = 0; i < n; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}