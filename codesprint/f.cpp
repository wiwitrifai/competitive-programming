#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int NLOG = 19;
const int N_MAT = 2;
const int mod = 1e9 + 7;

struct matrix {
  int n, m;
  long long _mat[N_MAT][N_MAT];
  matrix(int _n = 2, int _m = 2) : n(_n), m(_m) {
    memset(_mat, 0, sizeof _mat);
  }
  const long long * operator[](int id) const { return _mat[id]; }
  long long * operator[](int id) {return _mat[id]; }
  void identity() {
    for(int i = 0; i<n; i++)
      _mat[i][i] = 1;
  }
  matrix operator*(const matrix& mat) {
    matrix ret(this->n, mat.m);
    for(int i = 0; i<n; i++)
      for(int j = 0; j<mat.m; j++) {
        ret[i][j] = 0;
        for(int k = 0; k<m; k++) {
          ret[i][j] += _mat[i][k] * mat[k][j] % mod;
          ret[i][j] %= mod;
        }
      }
    return ret;
  }
  matrix operator+(const matrix& mat) {
    matrix ret(n, m);
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++)
        ret[i][j] = (_mat[i][j] + mat[i][j]) % mod;
    return ret;
  }
  matrix operator-(const matrix& mat) {
    matrix ret(n, m);
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++) {
        ret[i][j] = (_mat[i][j] - mat[i][j]) % mod;
        if(ret[i][j] < 0)
          ret[i][j] += mod;
      }
    return ret;
  }
  matrix operator^(long long pw) {
    matrix ret(n, m), base = *this;
    ret.identity();
    while(pw) {
      if(pw & 1)
        ret = ret * base;
      base = base * base;
      pw >>= 1;
    }
    return ret;
  }
  bool isNull() {
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++)
        if(_mat[i][j])
          return false;
    return true;
  }
  void print() {
    for(int i = 0; i<n; i++) {
      for(int j= 0; j<m; j++)
        cerr << _mat[i][j] << " ";
      cerr << endl;
    }
  }
};

matrix O(2, 2);
matrix I(2, 2);
matrix F[N<<1];
struct seg_tree {
  int n;
  matrix * seg;
  matrix * sum;
  seg_tree(int n_ = 0) : n(n_) {
  }
  void reset(int n_) {
    n = n_;
    seg = new matrix[n<<2];
    sum = new matrix[n<<2];
    build(1, 0, n);
  }
  void build(int id, int l, int r) {
    seg[id] = O;
    sum[id] = O;
    if(r-l < 2)
      return;
    int mid = (l+r) >>1, il = id <<1, ir = il|1;
    build(il, l, mid);
    build(ir, mid, r); 
  }
  void update(int x, matrix mat, int id, int l, int r) {
    if(r-l < 2) {
      sum[id] = sum[id] + mat;
      seg[id] = seg[id] + mat;
      return;
    }
    int mid = (l+r) >>1, il = id <<1, ir = il|1;
    if(x < mid)
      update(x, mat, il, l, mid);
    else
      update(x, mat, ir, mid, r);
    seg[id] = seg[il] * (F[(r-mid)]) + seg[ir];
    sum[id] = sum[il] + sum[ir];
  }

  pair<matrix, matrix> get(int x, int y, int id, int l, int r) {
    if(x >= r || y <= l) return make_pair(O, O);
    if(x <= l && r <= y)
      return make_pair(seg[id] * F[y-r], sum[id]);
    int mid = (l+r) >>1, il = id <<1, ir = il|1;
    pair<matrix, matrix> res1 = get(x, y, il, l, mid);
    pair<matrix, matrix> res2 = get(x, y, ir, mid, r);
    return make_pair(res1.first + res2.first, res1.second + res2.second);
  }
};

int n;
vector< int > child[N];
int p[N], lv[N], idx[N], com[N], ncom[N], com_x, sz_tree[N], head[N], par[N][NLOG];

void dfs(int v) {
  par[v][0] = p[v];
  for(int i = 0; i+1<NLOG; i++) {
    if(par[v][i] != -1)
      par[v][i+1] = par[par[v][i]][i];
    else
      par[v][i+1] = -1;
  }
  sz_tree[v] = 1;
  for(auto u : child[v]) {
    dfs(u);
    sz_tree[v] += sz_tree[u];
  }
}

void hld(int v) {
  if(p[v] + 1) {
    lv[v] = lv[p[v]] + 1;
  }
  else {
    lv[v] = 0;
    com_x = 0;
    ncom[com_x] = 0;
    head[com_x] = v;
  }
  com[v] = com_x;
  idx[v] = ncom[com_x]++;
  int best = -1, sz = 0;
  for(auto u : child[v]) if(sz < sz_tree[u]) {
    best = u;
    sz = sz_tree[u];
  }
  if(best + 1)
    hld(best);
  for(auto u : child[v]) if(u - best) {
    ncom[++com_x] = 0;
    head[com_x] = u;
    hld(u);
  }
}


seg_tree *stree;

int get_lca(int u, int v) {
  if(lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for(int i = 0; i<NLOG; i++) if(diff & (1<<i)) {
    v = par[v][i];
  }
  if(u == v)
    return u;
  for(int i = NLOG-1; i>=0; i--) if(par[v][i] != par[u][i]) {
    u = par[u][i];
    v = par[v][i];
  }
  return p[v];
}

long long get_sum(int v) {
  if(v < 0)
    return 0;
  int mv = 0;
  pair<matrix, matrix> segv = make_pair(O, O);
  while(v >= 0) {
    pair<matrix, matrix> res = stree[com[v]].get(0, idx[v]+1, 1, 0, stree[com[v]].n);
    segv.first = segv.first + res.first * (F[mv]);
    segv.second = segv.second + res.second;
    mv += idx[v] + 1;
    v = p[head[com[v]]];
  }
  segv.first = (segv.first * F[2]) - (segv.second * F[1]);
  return segv.first[0][0];
}

long long solve(int u, int v) {
  int lca = get_lca(u, v);
  long long ans = get_sum(u) + get_sum(v) - get_sum(lca) - get_sum(p[lca]);
  ans %= mod;
  if(ans < 0)
    ans += mod;
  return ans;
}

int main() {
  I.identity();
  F[0].identity();
  F[1][0][0] = F[1][0][1] = F[1][1][0] = 1;
  F[1][1][1] = 0;
  // F[0].print();
  int q;
  scanf("%d%d", &n, &q);
  for(int i = 2; i<(N<<1); i++)
    F[i] = F[i-1] * F[1];
  p[0] = -1;
  for(int i = 1; i<n; i++) {
    scanf("%d", p+i); p[i]--;
    child[p[i]].push_back(i);
  }
  dfs(0);
  hld(0);
  com_x++;
  stree = new seg_tree[com_x];
  for(int i = 0; i<com_x; i++) {
    stree[i].reset(ncom[i]);
  }
  while(q--) {
    char s[10];
    int x;
    long long y;
    scanf("%s%d%lld", s, &x, &y);
    x--; y--;
    if(s[0] == 'U') {
      matrix mat = F[1]^y;
      stree[com[x]].update(idx[x], mat, 1, 0, stree[com[x]].n);
    }
    else {
      printf("%lld\n", solve(x, y));
    }
  }
  return 0;
}