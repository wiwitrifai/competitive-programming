#include <bits/stdc++.h>

using namespace std;

const int N = 1004, inf = 1e8 + 7, Q = 1e5 + 5, K = 42;

int n, m;

int enc(int x, int y) {
  return x * m + y;
}

int a[N][N];
int to[K][K];
int lef[Q][K], rig[Q][K];
int vl[Q], vr[Q];
vector<int> g[N * N];
vector<int> elem[K];
int dist[N * N], ans[Q];

int main() {
  int k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i]+j);
      elem[a[i][j]].push_back(enc(i, j));
    }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int ra, ca, rb, cb;
    scanf("%d %d %d %d", &ra, &ca, &rb, &cb);
    --ra, --ca, --rb, --cb;
    vl[i] = enc(ra, ca);
    vr[i] = enc(rb, cb);
    ans[i] = abs(ra - rb) + abs(ca - cb);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i+1 < n) {
        g[enc(i, j)].push_back(enc(i+1, j));
        g[enc(i+1, j)].push_back(enc(i, j));
      }
      if (j + 1 < m) {
        g[enc(i, j)].push_back(enc(i, j+1));
        g[enc(i, j+1)].push_back(enc(i, j));
      }
    }
  }
  for (int i = 0; i <= k; ++i)
    for (int j = 0; j <= k; ++j) {
      to[i][j] = i == j ? 0 : inf;
    }
  for (int c = 1; c <= k; ++c) {
    fill(dist, dist+n*m, inf);
    queue<int> que;
    for (int u : elem[c]) {
      que.push(u);
      dist[u] = 0;
    }
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int u : g[v]) {
        if (dist[u] != inf) continue;
        dist[u] = dist[v] + 1;
        que.push(u);
      }
    }
    for (int i = 0; i < q; ++i) {
      lef[i][c] = dist[vl[i]];
      rig[i][c] = dist[vr[i]];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int now = a[i][j];
        to[c][now] = min(to[c][now], dist[enc(i, j)]);
      }
    }
  }
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= k; ++j)
      to[i][j] = min(to[i][j], to[j][i]);
  }
  for (int z = 0; z <= k; ++z) {
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j <= k; ++j) {
        to[i][j] = min(to[i][j], to[i][z] + to[z][j] + 1);
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int best = ans[i];
    for (int s = 1; s <= k; ++s) {
      for (int t = 1; t <= k; ++t) {
        int cur = lef[i][s] + rig[i][t];
        if (cur > best) continue;
        cur += to[s][t] + (s == t ? 1 : 2);
        best = min(best, cur);
      }
    }
    printf("%d\n", best);
  }
  return 0;
}
