#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, sz[N];
vector<tuple<int, int, int, int> > ans;
vector<int> cand[N];

bool dfs(int v, int par, int & a, int & b) {
  sz[v] = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    int x, y;
    bool res = dfs(u, v, x, y);
    if (!res) return 0;
    sz[v] += sz[u] + 1;
    if ((sz[u] % 3) == 0) {
      cand[v].push_back(u);
    }
    else {
      ans.emplace_back(u, v, x, y);
    }
  }
  while (cand[v].size() >= 3) {
    int x, y, z;
    x = cand[v].back(); cand[v].pop_back();
    y = cand[v].back(); cand[v].pop_back();
    z = cand[v].back(); cand[v].pop_back();
    ans.emplace_back(v, x, y, z);
  }
  if ((sz[v] % 3) == 1) return 0;
  if ((sz[v] % 3) == 0 && cand[v].size() != 0) return 0;
  if ((sz[v] % 3) == 2) { 
    if (cand[v].size() != 2) return 0;
    a = cand[v][0], b = cand[v][1];
    cand[v].clear();
  }
  return 1;
}

bool solve() {
  if ((n-1) % 3) return 0;
  for (int i = 0; i < n; ++i) cand[i].clear();
  int a, b;
  ans.clear();
  bool res = dfs(0, -1, a, b);
  if (!res) return 0;
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    ans.clear();
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    bool res = solve();
    if (res) {
      puts("YES");
      for (int i = 0; i < ans.size(); ++i) {
        int a, b, c, d;
        tie(a, b, c, d) = ans[i];
        printf("%d %d %d %d\n", a+1, b+1, c+1, d+1);
      }
    }
    else
      puts("NO");
  }
  return 0;
}