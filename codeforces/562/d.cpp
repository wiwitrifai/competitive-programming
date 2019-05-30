#include <bits/stdc++.h>

using namespace std;

const int N = 1.5e5 + 5;

int cnt[N][27], up[N][27];
int p[N], go[N], depth[N];
char col[N];
vector<int> child[N];
bool ok[N];

int find(int x) {
  return go[x] == x ? x : go[x] = find(go[x]);
}

int ord(char c) {
  if (c == '?')
    return 0;
  return c - 'a' + 1;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  int deep = 0;
  fill(ok, ok+n+1, 1);
  for (int i = 2; i <= n; ++i) {
    scanf("%d %s", p+i, col+i);
    child[p[i]].push_back(i);
    depth[i] = depth[p[i]] + 1;
    deep = max(deep, depth[i]);
  }
  bool fail = 0;
  for (int i = 1; i <= n; ++i) {
    go[i] = i;
    if (child[i].empty() && depth[i] < deep)
      fail = 1;
  }
  for (int i = 2; i <= n; ++i) {
    if (child[i].size() != 1) continue;
    go[i] = child[i][0];
    p[child[i][0]] = p[i];
  }
  for (int i = 2; i <= n; ++i) {
    ++up[find(i)][ord(col[i])];
  }
  for (int i = n; i >= 1; --i) {
    if (go[i] != i) continue;
    memset(cnt[i], 0, sizeof cnt[i]);
    ok[i] = 1;
    for (int u : child[i]) {
      u = find(u);
      for (int j = 0; j < 27; ++j) {
        cnt[i][j] = max(cnt[i][j], cnt[u][j] + up[u][j]);
      }
      ok[i] &= ok[u];
    }
    int sum = 0;
    for (int j = 1; j < 27; ++j)
      sum += cnt[i][j];
    ok[i] &= sum <= deep - depth[i];
  }
  while (q--) {
    int v;
    char buff[5];
    scanf("%d %s", &v, buff);
    if (fail) {
      puts("Fou");
      continue;
    }
    if (col[v] != buff[0]) {
      int u = find(v);
      --up[u][ord(col[v])];
      col[v] = buff[0];
      ++up[u][ord(col[v])];
      while (u != 1) {
        u = find(p[u]);
        memset(cnt[u], 0, sizeof cnt[u]);
        ok[u] = 1;
        for (int x : child[u]) {
          x = find(x);
          for (int j = 0; j < 27; ++j) {
            cnt[u][j] = max(cnt[u][j], cnt[x][j] + up[x][j]);
          }
          ok[u] &= ok[x];
        }
        int sum = 0;
        for (int j = 1; j < 27; ++j)
          sum += cnt[u][j];
        ok[u] &= sum <= deep - depth[u];
      }
    }
    int sum = 0;
    for (int i = 1; i < 27; ++i) {
      sum += cnt[1][i];
    }
    if (sum > deep || !ok[1]) {
      puts("Fou");
      continue;
    }
    int ans = 0;
    sum = deep-sum;
    for (int i = 1; i < 27; ++i) {
      ans += (sum + cnt[1][i]) * i;
    }
    printf("Shi %d\n", ans);
  }
  return 0;
}
