#include <bits/stdc++.h>

using namespace std;

const int M = 2, mod = 1e9 + 7, N = 3e5 + 5, LG = 20;

struct matrix {
  int a[M][M];
  matrix() {
    reset();
  }
  matrix operator+(const matrix & b) const {
    matrix ret;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        ret.a[i][j] = a[i][j] + b.a[i][j];
        if (ret.a[i][j] >= mod)
          ret.a[i][j] -= mod;
      }
    }
    return ret;
  }
  matrix operator*(const matrix & b) const {
    matrix ret;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        for (int k = 0; k < M; ++k) {
          ret.a[i][j] = (ret.a[i][j] + 1LL * a[i][k] * b.a[k][j]) % mod;
        }
      }
    }
    return ret;
  }
  matrix operator^(long long p) const {
    matrix ret;
    ret.identity();
    matrix b = *this;
    for(; p; p >>= 1, b = b * b)
      if (p & 1)
        ret = ret * b;
    return ret;
  }
  void identity() {
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < M; ++j)
        a[i][j] = (i == j);
  }
  void reset() {
    memset(a, 0, sizeof a);
  }
};

matrix fib(int a, int b) {
  matrix ret;
  ret.a[0][0] = b;
  ret.a[1][0] = a;
  return ret;
}

matrix mul[N];
int fib(int a, int b, int n) {
  matrix mat = mul[n] * fib(a, b);
  return mat.a[1][0];
}

struct BIT {
  vector<int> a;
  BIT() {
    a.clear();
  }
  void reset(int s) {
    a.assign(s, 0);
  }
  int get(int x) {
    int ret = 0;
    for (; x < a.size(); x += x&-x) {
      ret += a[x];
      if (ret >= mod) ret -= mod;
    }
    return ret;
  }
  void upd(int x, int val) {
    if (x < 0) return;
    x = min(x, (int)a.size()-1);
    for (; x; x -= x&-x) {
      a[x] += val;
      if (a[x] >= mod) a[x] -= mod;
    }
  }
};

struct node
{
  BIT a, b;
  BIT da, db; // to cancel
  void reset(int s) {
    a.reset(s);
    b.reset(s);
    da.reset(s);
    db.reset(s);
  }
} nodes[N];

vector<int> g[N];
int lv[N];
int eulertour[N + N], ntour = 0;
int sp[LG][N + N], st[N];
int getsp(int l, int r) {
  if (l > r) swap(l, r);
  int len = r - l + 1;
  int lg = 31 - __builtin_clz(len);
  int le = sp[lg][l], ri = sp[lg][r-(1 << lg) + 1];
  return lv[le] < lv[ri] ? le : ri;
}
int lca(int u, int v) {
  return getsp(st[u], st[v]);
}
int dist(int u, int v) {
  int w = lca(u, v);
  return lv[u] + lv[v] - 2 * lv[w];
}

void dfs(int v, int par = -1) {
  lv[v] = par == -1 ? 0 : lv[par] + 1;
  eulertour[ntour] = v;
  st[v] = ntour++;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    eulertour[ntour] = v;
    ntour++;
  }
}

int sz[N], to[N], vis[N];
vector<int> cen[N];

inline void getSize(int v, int par) {
  sz[v] = 1;
  to[v] = -1;
  for (int u : g[v]) if (u != par && !vis[u]) {
    getSize(u, v);
    sz[v] += sz[u];
    if (to[v] == -1 || sz[to[v]] < sz[u])
      to[v] = u;
  }
}
inline void assign(int v, int par, int vc) {
  cen[v].push_back(vc);
  for (int u : g[v]) if (u != par && !vis[u]) {
    assign(u, v, vc);
  }
}

void centroid(int v) {
  getSize(v, -1);
  int tot = sz[v];
  while (to[v] != -1 && 2 * sz[to[v]] > tot) v = to[v];
  nodes[v].reset(tot+2);
  assign(v, -1, v);
  vis[v] = 1;
  for (int u : g[v]) if (!vis[u])
    centroid(u);
}

inline void add(int & x, int y) { x += y; if (x >= mod) x -= mod; }

void update(int v, int k, int a, int b) {
  matrix cur = fib(a, b);
  for (int i = 0; i < cen[v].size(); ++i) {
    int p = cen[v][i];
    int d = dist(p, v);
    if (d <= k) {
      matrix res = mul[d] * cur;
      nodes[p].a.upd(k-d + 1, res.a[1][0]);
      nodes[p].b.upd(k-d + 1, res.a[0][0]);
      if (i) {
        int q = cen[v][i-1];
        nodes[q].da.upd(k-d+1, res.a[1][0]); 
        nodes[q].db.upd(k-d+1, res.a[0][0]); 
      }
    }
  }
}


int get(int v) {
  int ans = 0;
  for (int i = 0; i < cen[v].size(); ++i) {
    int p = cen[v][i];
    int d = dist(p, v);
    {
      int ca = nodes[p].a.get(d + 1);
      int cb = nodes[p].b.get(d + 1);
      add(ans, fib(ca, cb, d));
    }
    if (i) {
      int q = cen[v][i-1];
      int ca = nodes[q].da.get(d+1);
      int cb = nodes[q].db.get(d+1);
      add(ans, mod-fib(ca, cb, d));
    }
    if (ans >= mod)
      ans -= mod;
    if (ans < 0)
      ans += mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  return ans;
}

int main() {
  mul[0].identity();
  mul[1].reset();
  mul[1].a[0][0] = 1;
  mul[1].a[1][0] = 1;
  mul[1].a[0][1] = 1;
  mul[1].a[1][1] = 0;
  for (int i = 2; i < N; ++i)
    mul[i] = mul[i-1] * mul[1];
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ntour = 0;
    dfs(0);
    for (int i = 0; i < ntour; ++i)
      sp[0][i] = eulertour[i];
    for (int i = 0; i + 1 < LG; ++i) {
      for (int j = 0; j + (1 << (i + 1)) <= ntour; j++) {
        int le = sp[i][j], ri = sp[i][j + (1 << i)];
        sp[i+1][j] = lv[le] < lv[ri] ? le : ri;
      }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; ++i)
      cen[i].clear();
    centroid(0);
    for (int v = 0; v < n; ++v) {
      reverse(cen[v].begin(), cen[v].end());
    }

    while (q--) {
      int ty, v;
      scanf("%d %d", &ty, &v); v--;
      if (ty == 1) {
        int a, b, k;
        scanf("%d %d %d", &k, &a, &b);
        update(v, k, a, b);
      }
      else {
        printf("%d\n", get(v));
      }
    }
  }
  return 0;
}