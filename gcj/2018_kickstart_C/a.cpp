#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

vector<int> g[N];
int num[N], vis[N];

vector<int> S;
void dfs(int v, int par = -1) {
  if (num[v] != -1) return;
  if (vis[v]) {
    for (int i = (int)S.size()-1; i >= 0; --i) {
      num[S[i]] = 0;
      if (S[i] == v) break;
    }
    return;
  }
  vis[v] = 1;
  S.push_back(v);
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    if (num[v] == -1 && num[u] >= 0)
      num[v] = num[u]+1;
  }
  S.pop_back();
  vis[v] = 0;
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    g[i].clear();
  for (int i = 0; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(num, -1, sizeof num);
  for (int i = 0; i < n; ++i) {
    if (g[i].size() == 1) {
      dfs(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    num[i] = max(num[i], 0);
    printf("%d%c", num[i], i == n-1 ? '\n' : ' ');
  }
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}