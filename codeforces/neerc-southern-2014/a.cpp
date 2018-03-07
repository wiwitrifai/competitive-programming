#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 6, S = sqrt(N);

int p[N], ver = 0;
pair<int, int> his[N], edge[N], seg[N];

int find(int x) {
  while (p[x] >= 0) x = p[x];
  return x;
}

bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return 0;
  if (-p[u] > -p[v])
    swap(u, v);
  his[ver++] = {v, p[v]};
  his[ver++] = {u, p[u]};
  p[v] += p[u];
  p[u] = v;
  return 1;
}

void revert(int v) {
  if (v >= ver) return;
  while (ver > v) {
    --ver;
    p[his[ver].first] = his[ver].second;
  }
}

vector<pair<int, int> > que[N];
int ans[N];

int main() {
  ver = 0;
  memset(p, -1, sizeof p);
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edge[i] = {u, v};
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r); --l;
    seg[i] = {l, r};
    que[l/S].emplace_back(r, i);
  }
  for (int i = 0; i * S < q; ++i) {
    if (que[i].empty()) continue;
    revert(0);
    int r = i * S + S;
    sort(que[i].begin(), que[i].end());
    bool ok = 1;
    for (auto it : que[i]) {
      int id = it.second;
      while (r < seg[id].second && ok) {
        int u = edge[r].first, v = edge[r].second; ++r;
        merge(u, v+n);
        merge(v, u+n);
        if (find(u) == find(u+n))
          ok = 0;
      }
      if (!ok) {
        ans[id] = 0;
        continue;
      }
      int last = ver;
      ans[id] = 1;
      for (int j = min(seg[id].second, (i+1) * S)-1; j >= seg[id].first; --j) {
        int u = edge[j].first, v = edge[j].second;
        merge(u, v+n);
        merge(v, u+n);
        if (find(u) == find(u+n)) {
          ans[id] = 0;
          break;
        }
      }
      revert(last);
    }
  }
  for (int i = 0; i < q; ++i)
    puts(ans[i] ? "Possible" : "Impossible");
  return 0;
}