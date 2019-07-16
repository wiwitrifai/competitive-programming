#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

vector<int> que[N];
vector<pair<int, int> > edge[N];
int a[N], b[N], ans[N], w[N];
vector<int> nodes;
int p[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  memset(p, -1, sizeof p);
  int n, q, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", w+i);
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    int d = gcd(w[u], w[v]);
    edge[d].emplace_back(u, v);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", a+i, b+i);
    --a[i], --b[i];
    int d = gcd(w[a[i]], w[b[i]]);
    que[d].push_back(i);
    ans[i] = 1;
  }
  for (int d = 2; d < N; ++d) {
    int cnt = 0;
    for (int j = d; j < N; j += d)
      cnt += que[j].size();
    if (cnt == 0) continue;
    for (int j = d; j < N; j += d) {
      for (auto it : edge[j]) {
        // cerr << " merge " << it.first << " " << it.second << " " << d << endl;
        nodes.push_back(it.first);
        nodes.push_back(it.second);
        merge(it.first, it.second);
      }
    }
    for (int j = d; j < N; j += d) {
      for (int x : que[j]) {
        // cerr << " query " << a[x] << " " << b[x] << endl;
        if (find(a[x]) == find(b[x]))
          ans[x] = d;
      }
    }
    for (int u : nodes)
      p[u] = -1;
    nodes.clear();
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}