#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 5, S = 3000;

vector<int> g[N], e[N];
vector<int> nodes;
bool used[N];
int n;
int last;
void build(int id = 1, int l = 0, int r = n) {
  last = max(id, last);
  g[id].clear();
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void rec(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    nodes.push_back(id);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  rec(x, y, il, l, mid);
  rec(x, y, ir, mid, r);
}

void get(int x, int id = 1, int l = 0, int r = n) {
  nodes.push_back(id);
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    get(x, il, l, mid);
  else
    get(x, ir, mid, r);
}
vector<int> cover;

int cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d %d", &n, &m);
    last = 0;
    build();
    ++last;
    set<pair<int, int> > edge;
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      vector<int> nu, nv;
      nodes.clear();
      get(u);
      nu.swap(nodes);
      nodes.clear();
      get(v);
      nv.swap(nodes);
      for (int au : nu) {
        for (int av : nv) {
          int x = au, y = av;
          if (x > y) swap(x, y);
          edge.emplace(x, y);
        }
      }
    }
    cerr << " done " << edge.size() << endl;
    fill(cnt, cnt + last, 0);
    for (auto it : edge) {
      ++cnt[it.first];
      ++cnt[it.second];
    }
    for (auto it : edge) {
      int u = it.first, v = it.second;
      if (cnt[u] > cnt[v])
        swap(u, v);
      g[u].push_back(v);
      --cnt[v];
    }
    int big = 0;
    for (int i = 0; i < last; ++i)
      big = max((int)g[i].size(), big);
    // cerr << " big = " << big << endl;
    int q;
    scanf("%d", &q);
    while (q--) {
      int k;
      scanf("%d", &k);
      cover.clear();
      while (k--) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l;
        nodes.clear();
        rec(l, r);
        for (int u : nodes) {
          used[u] = 1;
          cover.push_back(u);
        }
      }
      bool ans = 1;
      for (int u : cover) {
        for (int v : g[u])
          if (used[v]) {
            ans = 0;
            break;
          }
        if (!ans)
          break;
      }
      for (int u : cover)
        used[u] = 0;
      puts(ans ? "YES" : "NO");
    }
  }
  return 0;
}