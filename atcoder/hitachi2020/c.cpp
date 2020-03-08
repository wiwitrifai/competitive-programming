#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];

vector<int> nodes[2];
int col[N], ans[N], used[N];

void dfs(int v, int par) {
  nodes[col[v]].push_back(v);
  for (int u : g[v]) {
    if (u == par) continue;
    col[u] = !col[v];
    dfs(u, v);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0);
  int cnt3 = n / 3;
  if ((int)nodes[0].size() <= cnt3 || (int)nodes[1].size() <= cnt3) {
    int small = nodes[0].size() < nodes[1].size() ? 0 : 1;
    int now = 3;
    for (int u : nodes[small]) {
      ans[u] = now;
      used[now] = 1;
      now += 3;
    }
    now = 1;
    for (int u : nodes[small^1]) {
      while (used[now]) ++now;
      ans[u] = now;
      used[now] = 1;
    }
  }
  else {
    int now1 = 1, now2 = 2, now3 = 3;
    for (int u : nodes[0]) {
      if (now1 <= n) {
        ans[u] = now1;
        now1 += 3;
      }
      else {
        ans[u] = now3;
        now3 += 3;
      }
    }
    for (int u : nodes[1]) {
      if (now2 <= n) {
        ans[u] = now2;
        now2 += 3;
      }
      else {
        ans[u] = now3;
        now3 += 3;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], i + 1 == n ? '\n' : ' ');
  }
  return 0;
}
