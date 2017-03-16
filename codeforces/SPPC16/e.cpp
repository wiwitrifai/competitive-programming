#include <bits/stdc++.h>

using namespace std;

#define MAXN 200000

int c[MAXN+5], vis[MAXN+5], t[MAXN+5];
vector<int> edge[MAXN+5];
set<int> unseen;

int dfs(int v, int d)
{
  c[v] = d % 2;
  int ret = 0;
  if (t[v]) {
    vector<int> nxt;
    set<int> t;
    for (const auto &u: edge[v]) {
      t.insert(u);
    }
    for (const auto &u: unseen) {
      if (t.count(u) == 0) nxt.push_back(u);
    }
    unseen = t;
    for (const auto &u: nxt) {
      if (vis[u]) continue;
      vis[u] = 1;
      ret += dfs(u, d+1);
    }
  }
  else {      
    for (const auto &u: edge[v]) {
      if (vis[u]) continue;
      vis[u] = 1;
      ret += dfs(u, d+1);
    }
  }
  return 1+ret;
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    char ch[3];
    int p;
    scanf("%s%d", ch, &p);
    unseen.insert(i);
    if (ch[0] == 'C') t[i] = 0;
    else t[i] = 1;
    for (int j = 0; j < p; ++j) {
      int a;
      scanf("%d", &a);
      edge[i].push_back(a);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    vis[i] = 1;
    int r = dfs(i, 0);
    if (r == 1) {
      puts("Impossible");
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%c", (c[i]) ? 'S' : 'V');
  }
  puts("");
}