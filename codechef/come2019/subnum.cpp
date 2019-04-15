#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int len[N];
vector<int> pre[N];
bool vis[N];

void dfs(int v) {
  if (vis[v]) return;
  vis[v] = 1;
  for (int u : pre[v]) {
    dfs(u);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int s, n;
    scanf("%d %d", &s, &n);
    vector<int> d(s);
    queue<int> que;
    memset(len, -1, sizeof len);
    for (int i = 0; i < n; ++i)
      pre[i].clear();
    for (int i = 0; i < s; ++i) {
      scanf("%d", &d[i]);
      if (d[i]) {
        int x = d[i] % n;
        if (len[x] == -1) {
          len[x] = 1;
          que.push(x);
        }
      }
    }
    sort(d.begin(), d.end());
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int x : d) {
        int u = (v * 10 + x) % n;
        if (len[u] != -1) continue;
        len[u] = len[v] + 1;
        que.push(u);
      }
    }
    if (len[0] == -1) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (len[i] == -1) continue;
      for (int x : d) {
        int u = (i * 10 + x) % n;
        if (len[u] == -1) continue;
        if (len[u] != len[i] + 1) continue;
        pre[u].push_back(i);
      }
    }
    memset(vis, 0, sizeof vis);
    dfs(0);
    int start = -1;
    for (int x : d) {
      if (x == 0) continue;
      int v = x % n;
      if (!vis[v]) continue;
      printf("%d", x);
      start = v;
      break;
    }
    assert(start != -1);
    while (start != 0) {
      for (int x : d) {
        int u = (start * 10 + x) % n;
        if (!vis[u]) continue;
        if (len[u] != len[start] + 1) continue;
        printf("%d", x);
        start = u;
        break;
      }
    }
    printf("\n");
  }

  return 0;
}
