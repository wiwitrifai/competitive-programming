#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int num_nodes = 2;

struct Node {
  int to[26];
  vector<int> labels;
  int length;
  int suff;
  Node() {
    memset(to, -1, sizeof to);
    length = 0;
    suff = 1;
  }
} nodes[N];

char s[N];

int add(int id, int x) {
  while (true) {
    if (x - nodes[id].length >= 1 && s[x - nodes[id].length - 1] == s[x])
      break;
    id = nodes[id].suff;
  }
  if (nodes[id].to[s[x]-'a'] != -1)
    return nodes[id].to[s[x]-'a'];
  nodes[id].to[s[x]-'a'] = num_nodes;
  nodes[num_nodes].length = nodes[id].length + 2;
  int suff = nodes[id].suff;
  id = num_nodes++;
  if (nodes[id].length == 1) {
    nodes[id].suff = 1;
    return id;
  }
  while (true) {
    if (x-nodes[suff].length >= 1 && s[x-nodes[suff].length-1] == s[x])
      break;
    suff = nodes[suff].suff;
  }
  nodes[id].suff = nodes[suff].to[s[x]-'a'];
  return id;
}

struct SegTree {
  int n;
  vector<int> mul;
  SegTree() {};
  SegTree(int n) : n(n), mul(n << 2, 0) {};
  void Build(int n_) {
    n = n_;
    mul.assign(n << 2, 0);
  }
  void Update(int x, int v) {
    Update_(x, v, 1, 0, n);
  }
  void Update_(int x, int v, int id, int l, int r) {
    if (r-l < 2) {
      mul[id] = v % mod;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (x < mid)
      Update_(x, v, il, l, mid);
    else
      Update_(x, v, ir, mid, r);
    mul[id] = 1LL * mul[il] * mul[ir] % mod;
  }
};
vector<int> child[N];
SegTree segtree;
int cnt[N], sz[N];

void get_sz(int v) {
  sz[v] = nodes[v].labels.size();
  for (int u : child[v]) {
    get_sz(u);
    sz[v] += sz[u];
  }
}

void add_seg(int id, int v) {
  cnt[id] += v;
  segtree.Update(id, cnt[id]);
}

void add_batch(int v, int d) {
  for (int x : nodes[v].labels)
    add_seg(x, d);
  for (int u : child[v])
    add_batch(u, d);
}

int solve(int v) {
  int big = -1;
  for (int u : child[v]) {
    if (big == -1 || sz[u] > sz[big])
      big = u;
  }
  int ret = 0;
  for (int u : child[v]) {
    if (u == big) continue;
    ret += solve(u);
    if (ret >= mod)
      ret -= mod;
    add_batch(u, -1);
  }
  if (big != -1) {
    ret += solve(big);
    if (ret >= mod)
      ret -= mod;
  }
  for (int u : child[v]) {
    if (u == big) continue;
    add_batch(u, +1);
  }
  for (int x : nodes[v].labels)
    add_seg(x, +1);
  if (v > 1) {
    ret += segtree.mul[1];
    if (ret >= mod)
      ret -= mod;
  }
  return ret;
}

int main() {
  nodes[0].length = -1;
  nodes[1].suff = 0;
  int n;
  scanf("%d", &n);
  long long q = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s);
    int now = 0;
    for (int j = 0; j < len; ++j) {
      now = add(now, j);
      if (now > 1)
        nodes[now].labels.push_back(i);
    }
    len = (1LL * len * (len + 1) / 2) % mod;
    q = q * len % mod;
  }
  for (int i = 1; i < num_nodes; ++i) {
    child[nodes[i].suff].push_back(i);
  }
  segtree.Build(n);
  get_sz(0);
  long long p = solve(0);
  cerr << p << " " << q << endl;
  long long ans = p * powmod(q, mod-2) % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
