#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N];
int rate[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

int merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    while (1);
    return -1;
  }
  if (rate[u] < rate[v])
    swap(u, v);
  p[u] = v;
  return u;
}
int n, q;
struct Node {
  int il, ir;
  long long sum;
  Node() : il(0), ir(0), sum(0) {}
};
vector<Node> seg;

void combine(int id) {
  seg[id].sum = seg[seg[id].il].sum + seg[seg[id].ir].sum;
}

vector<int> nodes;
int build(int l = 0, int r = n) {
  int id = seg.size();
  seg.push_back(Node());
  if (r-l < 2) {
    seg[id].sum = rate[nodes[l]];
    return id;
  }
  int mid = (l + r) >> 1;
  int res = build(l, mid);
  seg[id].il = res;
  res = build(mid, r);
  seg[id].ir = res;
  combine(id);
  return id;
}

int update(int x, int v, int id, int l = 0, int r = n) {
  int newid = seg.size();
  seg.push_back(seg[id]);
  if (r-l < 2) {
    seg[newid].sum = v;
    return newid;
  }
  int mid = (l + r) >> 1;
  if (x < mid) {
    int res = update(x, v, seg[id].il, l, mid);
    seg[newid].il = res;
  }
  else {
    int res = update(x, v, seg[id].ir, mid, r);
    seg[newid].ir = res;
  }
  combine(newid);
  return newid;
}

long long get(int x, int y, int id, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y)
    return seg[id].sum;
  int mid = (l + r) >> 1;
  return get(x, y, seg[id].il, l, mid) + get(x, y, seg[id].ir, mid, r);
}
vector<int> root;

int main() {
  scanf("%d %d", &n, &q);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    edges.emplace_back(w, u, v);
  }
  sort(edges.begin(), edges.end());
  for (int i = 0; i < n; ++i)
    scanf("%d", rate+i);
  fill(p, p+n, -1);
  vector<int> removed;
  for (auto e : edges) {
    int u, v;
    tie(ignore, u, v) = e;
    removed.push_back(merge(u, v));
  }
  nodes.resize(n);
  iota(nodes.begin(), nodes.end(), 0);
  sort(nodes.begin(), nodes.end(), [&](int l, int r) {
    return rate[l] < rate[r];
  });
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[nodes[i]] = i;
  }
  root.push_back(build());
  for (int v : removed) {
    int res = update(pos[v], 0, root.back());
    root.push_back(res);
  }
  long long ans = 0;
  for (int i = 0; i < q; ++i) {
    long long d, t, x;
    scanf("%lld %lld %lld", &d, &t, &x);
    d ^= ans;
    t ^= ans;
    x ^= ans;
    int version = lower_bound(edges.begin(), edges.end(), make_tuple(d+1, -1, -1)) - edges.begin();
    int from = lower_bound(nodes.begin(), nodes.end(), x, [&](int node, long long val) {
      return rate[node] * t < val;
    }) - nodes.begin();
    ans = get(from, n, root[version]) * t;
    printf("%lld\n", ans);
  }
  return 0;
}
