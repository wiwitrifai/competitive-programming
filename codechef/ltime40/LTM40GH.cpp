#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LN = 29;

struct node {
  node * l, *r;
  node() : l(NULL), r(NULL) {
  }
  ~node() {
    if (this->l)
      delete this->l;
    if (this->r)
      delete this->r;
  }
  void insert(int v) {
    // cerr << "insert " << v << endl;
    node * now = this;
    for (int i = 1 << (LN-1); i; i >>= 1) {
      if (v & i) {
        if (!now->r)
          now->r = new node();
        now = now->r;
      }
      else {
        if (!now->l)
          now->l = new node();
        now = now->l;
      }
    }
  }

  int get(int v) {
    // cerr << "get " << v << endl;
    node * now = this;
    int ret = 0;
    for (int i = 1 << (LN-1); i; i >>= 1) {
      if (v & i) {
        if (now->l) {
          ret |= i;
          now = now->l;
        }
        else if (now->r) {
          now = now->r;
        }
        else
          return 0;
      }
      else {
        if (now->r) {
          ret |= i;
          now = now->r;
        }
        else if (now->l)
          now = now->l;
        else
          return 0;
      }
    }
    return ret;
  }
};

int p[N], val[N], sz[N], a[N];
vector< int > adj[N];
void dfs(int v, int xr = 0) {
  sz[v] = 1;
  xr ^= a[v];
  val[v] = xr;
  for (int u : adj[v]) if (u != p[v]) {
    p[u] = v;
    dfs(u, xr);
    sz[v] += sz[u];
  }
}

int ans[N];
node * root;

void upd(int v, int xr = 0) {
  root->insert(val[v]^xr);
  for (int u : adj[v]) if (u != p[v]) {
    upd(u, xr);
  }
}
int get(int v, int xr) {
  int ret = root->get(val[v] ^ xr);
  // // cerr << v << " ans " << ans[v] << " " << val[v] << " " << xr << endl;
  for (int u : adj[v]) if (u != p[v])
    ret = max(ret, get(v, xr));
  return ret;
}
void buildhld(int v) {
  int big = -1, ts = 0;
  for (int u : adj[v]) if (u != p[v]) {
    if (ts < sz[u]) {
      big = u;
      ts = sz[u];
    }
  }
  ans[v] = a[v];
  for (int u : adj[v]) if (u != p[v] && u != big) {
    buildhld(u);
    ans[v] = max(ans[v], ans[u]);
  }
  if (big != -1) {
    buildhld(big);
    ans[v] = max(ans[v], ans[big]);
    for (int u : adj[v]) if (u != p[v] && u != big) {
      ans[v] = max(ans[v], get(u, a[v]));
      upd(u);
    }
    ans[v] = max(ans[v], root->get(a[v] ^ val[v]));
  }
  else {
    if (root)
      delete root;
    root = new node();
  }
  root->insert(val[v]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (root)
      delete root;
    root = new node();
    p[0] = 0;
    dfs(0);
    buildhld(0);
    for (int i = 0; i < n; i++)
      printf("%d\n", ans[i]);
    printf("\n");
  }
  return 0;
}