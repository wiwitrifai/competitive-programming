#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4, R = 301;

int x[N][4];

int p[N], cnt[N];
vector<int> g[R * R + 5];
bool vis[R * R + 5];
int rig[R+5][R+5];
int up[R+5][R+5];
char ans[R+5][R+5];

int enc(int a, int b) {
  return a * R + b;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j)
      scanf("%d", x[i]+j);
    if (x[i][1] > x[i][3])
      swap(x[i][1], x[i][3]);
    if (x[i][0] > x[i][2])
      swap(x[i][0], x[i][2]);
    int u = enc(x[i][0], x[i][1]), v = enc(x[i][2], x[i][3]);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int a, b;
  scanf("%d %d", &a, &b);
  int s = enc(a, b);
  for (int i = 0; i < n; ++i) {
    if (x[i][0] <= a && a <= x[i][2] && x[i][1] <= b && b <= x[i][3]) {
      g[s].push_back(enc(x[i][0], x[i][1]));
      g[s].push_back(enc(x[i][2], x[i][2]));
    }
  }
  queue<int> que;
  que.push(s);
  vis[s] = 1;
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int u : g[v]) {
      if (vis[u]) continue;
      vis[u] = 1;
      que.push(u);
    }
  }
  memset(up, -1, sizeof up);
  memset(rig, -1, sizeof rig);
  for (int i = 0; i < n; ++i) {
    if (!vis[enc(x[i][0], x[i][1])] && !vis[enc(x[i][2], x[i][3])])
      continue;
    if (x[i][0] == x[i][2]) {
      up[x[i][0]][x[i][1]] = max(up[x[i][0]][x[i][1]], x[i][3]);
    }
    else {
      assert(x[i][1] == x[i][3]);
      rig[x[i][0]][x[i][1]] = max(rig[x[i][0]][x[i][1]], x[i][2]);
    }
  }
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < R; ++j)
      ans[i][j] = '.';
  for (int i = 0; i < R; ++i) {
    for (int j = 0, k = 0; j < R; ++j) {
      k = max(k, j);
      while (k <= up[i][j]) {
        ans[i][k++] = '#';
      }
    }
    for (int j = 0, k = 0; j < R; ++j) {
      k = max(k, j);
      while (k <= rig[j][i]) {
        ans[k++][i] = '#';
      }
    }
  }
  int xlow = R+1, xhig = -1, ylow = R+1, yhig = -1;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < R; ++j) {
      if (ans[i][j] != '#') continue;
      xlow = min(xlow, i);
      xhig = max(xhig, i);
      ylow = min(ylow, j);
      yhig = max(yhig, j);
    }
  }
  for (int i = yhig; i >= ylow; --i) {
    for (int j = xlow; j <= xhig; ++j) {
      printf("%c", ans[j][i]);
    }
    printf("\n");
  }
  return 0;
}