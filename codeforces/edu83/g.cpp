#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<pair<char, int>> g[N];
int mark[N], ans[N], pos[N];
int lv[N], pre[N];

int cnt = 0;

void predfs(int v) {
  cnt += mark[v];
  pre[v] = cnt;
  for (auto e : g[v]) {
    lv[e.second] = lv[v] + 1;
    predfs(e.second);
  }
}

void dfs(int v, int a, int b) {
  ans[v] = lv[v] + a;
  if (mark[v])
    ans[v] = min(ans[v], pre[v] + b);
  a = min(a, ans[v] - lv[v]);
  b = min(b, ans[v] - pre[v] + mark[v]);
  for (auto e : g[v]) {
    dfs(e.second, a, b);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int p;
    char s[4];
    scanf("%d %s", &p, s);
    g[p].emplace_back(s[0], i);
  }
  for (int i = 0; i <= n; ++i) {
    sort(g[i].begin(), g[i].end());
  }
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i) {
    int x;
    scanf("%d", &x);
    mark[x] = 1;
    pos[i] = x;
  }
  predfs(0);
  dfs(0, 0, 0);
  for (int i = 1; i <= k; ++i) {
    printf("%d%c", ans[pos[i]], i == k ? '\n' : ' ');
  }
  return 0;
}
