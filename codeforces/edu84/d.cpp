#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> factors[N];

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i)
      factors[j].push_back(i);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> p(n), c(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &p[i]);
      --p[i];
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &c[i]);
    }
    int ans = n+1;
    vector<bool> vis(n, false);
    for (int v = 0; v < n; ++v) {
      if (vis[v]) continue;
      int cur = v, cnt = 0;
      vector<int> nodes;
      while (!vis[cur]) {
        ++cnt;
        vis[cur] = 1;
        nodes.push_back(cur);
        cur = p[cur];
      }
      for (int len : factors[cnt]) {
        bool found = 0;
        for (int x = 0; x < len && !found; ++x) {
          found = 1;
          for (int y = x; y < cnt && found; y += len) {
            found &= c[nodes[x]] == c[nodes[y]];
          }
        }
        if (found)
          ans = min(ans, len);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
