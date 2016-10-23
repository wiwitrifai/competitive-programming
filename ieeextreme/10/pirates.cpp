/**
  IEEExtreme Programming Contest 10
  Problem : Pirates
  Solver  : Luqman Arifin S
*/



#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int di[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dj[] = {-1, 0, 1, 1, -1, 1, 0, -1};

// all zero based
char s[N][N];
int node[N][N], n, m, q;

int cost[N * N], h[N * N], dp[N * N];
set<int> edge[N * N];
vector<int> st;
int rmq[2 * N * N][22], lef[N * N], rig[N * N];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j, int col) {
  if (node[i][j] != -1) return;
  node[i][j] = col;
  for (int k = 0; k < 8; k++) {
    int ti = i + di[k];
    int tj = j + dj[k];
    if (valid(i, j) && s[ti][tj] == s[i][j]) {
      dfs(ti, tj, col);
    }
  }
}

void dfs(int now, int bef) {
  lef[now] = st.size();
  st.push_back(now);
  dp[now] += cost[now];
  for (auto it : edge[now]) {
    if (it == bef) continue;
    h[it] = h[now] + 1;
    dp[it] = dp[now];
    dfs(it, now);
    st.push_back(now);
  }
  rig[now] = st.size() - 1;
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return (h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g]);
}

int solve(int u, int v) {
  int root = lca(u, v);
  //printf("%d %d root %d\n", u, v, root);
  return dp[u] - dp[root] + dp[v] - dp[root] + cost[root];
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      node[i][j] = -1;
    }
  }
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  
  int nodes = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (node[i][j] == -1) {
        if (s[i][j] == 'O') {
          cost[nodes] = 1;
        }
        dfs(i, j, nodes);
        nodes++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      //printf("%d", node[i][j]);
      for (int k = 0; k < 8; k++) {
        int ti = i + di[k];
        int tj = j + dj[k];
        if (valid(ti, tj) && node[i][j] != node[ti][tj]) {
          edge[node[i][j]].insert(node[ti][tj]);
        }
      }
    }
    //printf("\n");
  }
  dfs(0, -1);
  //puts("done dfs");
  //for (int i = 0; i < nodes; i++) printf("%d %d\n", i, dp[i]);
  for (int i = 0; i < st.size(); i++) {
    rmq[i][0] = st[i];
  }
  // build rmq with sparse table
  for (int j = 1; (1 << j) <= st.size(); j++) {
    for (int i = 0; i + (1 << j) <= st.size(); i++) {
      rmq[i][j] = (h[rmq[i][j - 1]] < h[rmq[i+(1<<(j-1))][j - 1]]? rmq[i][j - 1] : rmq[i+(1<<(j-1))][j - 1]);
    }
  }
  /*
  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      printf("lca %d %d: %d\n", i, j, lca(i, j));
    }
  }
  for (auto it : st) printf("%d ", it); printf("\n");
  */
  //puts("done with rmq");
  while (q--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--; c--; d--;
    printf("%d\n", solve(node[a][b], node[c][d]));
  }
  
  return 0;
}
