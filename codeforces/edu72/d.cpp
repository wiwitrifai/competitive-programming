#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

vector<int> g[N];
int a[N], b[N], din[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    a[i] = u;
    b[i] = v;
    g[u].push_back(v);
    ++din[v];
  }
  vector<int> topo;
  for (int i = 0; i < n; ++i) {
    if (din[i] == 0)
      topo.push_back(i);
  }
  for (int i = 0; i < (int)topo.size(); ++i) {
    int v = topo[i];
    for (int u : g[v]) {
      --din[u];
      if (din[u] == 0) {
        topo.push_back(u);
      }
    }
  }
  if ((int)topo.size() == n) {
    printf("1\n");
    for (int i = 0; i < m; ++i) {
      printf("1%c", i+1 == m ? '\n' : ' ');
    }
    return 0;
  }
  printf("2\n");
  for (int i = 0; i < m; ++i) {
    printf("%d%c", 1 + (a[i] < b[i]), i+1 == m ? '\n' : ' ');
  }
  return 0;
}
