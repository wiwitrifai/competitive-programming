#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector< int > g[N];
set< int > e[N];
int p[N], n, m, q;
long long fs[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
      g[i].clear();
      e[i].clear();
      e[i].insert(i);
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    memset(p, -1, sizeof p);
    memset(fs, 0, sizeof fs);
    while (q--) {
      int x, y, z;
      scanf("%d %d", &x, &y);
      if (x == 1) {
        scanf("%d", &z);
        y--; z--;
        y = find(y), z = find(z);
        if (y == z) continue;
        if (-p[y] < -p[z])
          swap(y, z); 
        p[y] += p[z];
        p[z] = y;
        fs[y] += fs[z];
        for (int v : e[z]) {
          for (int u : g[v])
            fs[y] += e[y].count(u);  
        }
        for (int v : e[z])
          e[y].insert(v);
      }
      else {
        printf("%lld\n", fs[find(y-1)]);
      }
    }
  }
  return 0;
}