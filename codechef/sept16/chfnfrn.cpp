#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int n, m;
bitset< N > adj[N], bc[2];
int com[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      adj[i].reset();
      adj[i][i] = 1;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u; --v;
      adj[u][v] = 1;
      adj[v][u] = 1;
    }
    memset(com, -1, sizeof com);
    bc[0].reset();
    bc[1].reset();
    for (int j = 0; j < n; j++) if (com[j] == -1) {
      queue< int > q;
      q.push(j);
      com[j] = 0;
      bc[0][j] = 1;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n; i++) if (adj[u][i] == 0 && com[i] == -1) {
          q.push(i);
          com[i] = com[u] ^ 1;
          bc[com[i]][i] = 1;
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if ((adj[i] & bc[com[i]]) != bc[com[i]]) {
        ok = false;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }

  return 0;
}