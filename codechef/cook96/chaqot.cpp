#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    for (int i = 1;i < n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int ans = 0;
    while (q--) {
      int r, k;
      scanf("%d %d", &r, &k);
      r ^= ans;
      vector<int> su;
      for (int i = 0; i < k; ++i) {
        int u;
        scanf("%d", &u);
        u ^= ans;
        --u;
        su.push_back(u);
      }
      int root = su[0];
      for (int i = 1; i < k; ++i) {
        root = lca(root, su[i]);
      }
      for (int u : su) {
        
      }
    }
  }
  return 0;
}