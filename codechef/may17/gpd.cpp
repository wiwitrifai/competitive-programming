#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;
int l[32 * N], r[32 * N], cur;
map< int, int > root;
int add(int now, int val) {
  int ret = cur;
  for (int i = 30; i >= 0; i--) {
    l[cur] = l[now];
    r[cur] = r[now];
    if (val & (1<<i)) {
      now = r[now];
      r[cur] = cur+1;
    }
    else {
      now = l[now];
      l[cur] = cur+1;
    }
    cur++;
  }
  return ret;
}
int getmax(int now, int val) {
  int ret = 0;
  for (int i = 30; i >= 0; i--) {
    if (val & (1<<i)) {
      if (l[now])
        now = l[now];
      else
        now = r[now], ret |= 1<<i;
    }
    else {
      if (r[now])
        now = r[now], ret |= 1<<i;
      else
        now = l[now];
    }
  }
  return ret;
}
int getmin(int now, int val) {
  int ret = 0;
  for (int i = 30; i >= 0; i--) {
    if (val & (1<<i)) {
      if (r[now])
        now = r[now], ret |= 1<<i;
      else
        now = l[now];
    }
    else {
      if (l[now])
        now = l[now];
      else
        now = r[now], ret |= 1<<i;
    }
  }
  return ret;
}
map<int, vector< pair<int, int> > > g;
void dfs(int v) {
  for (auto it : g[v]) {
    root[it.first] = add(root[v], it.second);
    dfs(it.first);
  }
}

int main() {
  l[0] = r[0] = 0;
  cur = 1;
  int n, q, r, k;
  scanf("%d %d", &n, &q);
  scanf("%d %d", &r, &k);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    g[v].emplace_back(u, w);
  }
  root[r] = add(0, k);
  dfs(r);
  int last_answer = 0;
  while (q--) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);
    t ^= last_answer;
    u ^= last_answer;
    v ^= last_answer;
    if (t == 0) {
      scanf("%d", &k);
      k ^= last_answer;
      root[v] = add(root[u], k);
    }
    else {
      int mi = getmin(root[u], v) ^ v, ma = getmax(root[u], v) ^ v;
      printf("%d %d\n", mi, ma);
      last_answer = mi ^ ma;
    }
  }
  return 0;
}