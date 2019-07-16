#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], c[N];
int child[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> nodes;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", a+i, b+i, c+i);
    nodes.push_back(a[i]);
    nodes.push_back(b[i]);
  }
  sort(nodes.begin(), nodes.end());
  nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(nodes.begin(), nodes.end(), a[i]) - nodes.begin();
    b[i] = lower_bound(nodes.begin(), nodes.end(), b[i]) - nodes.begin();
  }
  vector<tuple<int, int, int> > edge(n);
  for (int i = 0; i < n; ++i) {
    edge[i] = make_tuple(c[i], a[i], b[i]);
  }
  sort(edge.begin(), edge.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int w, u, v;
    tie(w, u, v) = edge[i];
    if (child[u] == 0) {
      ++ans;
      child[u] += m;
    }
    --child[u];
    child[v] += m;
  }
  printf("%d\n", ans);
  return 0;
}