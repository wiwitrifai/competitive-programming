#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector< int > adj[N];
int a[3 * N], b[3 * N], die[3 * N];
int vis[N], used[N];

bool dfs(list< int >::iterator it, list< int >::iterator to, list< int > &res) {
  // cerr << *it << " " << *to << endl;
  if (*it == *to) {
    res.erase(to);
    return true;
  }
  if (vis[*it])
    return false;
  if (used[*it])
    return false;
  used[*it] = true;
  vis[*it] = 1;
  for (int c : adj[*it]) if (!die[c]) {
    int u = a[c] ^ b[c] ^ *it;
    die[c] = 1;
    auto tmp = res.insert(to, u);
    bool ok = dfs(tmp, to, res);
    if (ok)
      return true;
    die[c] = 0;
    res.erase(tmp);
  }
  used[*it] = false;
  return false;
}

void dfs2(int u) {
  if (!vis[u])
    return;
  vis[u] = 0;
  for (int i : adj[u]) {
    int v = a[i] ^ b[i] ^ u;
    dfs2(v);
  }
}

int main() {
  freopen("drawing.in", "r", stdin);
  freopen("drawing.out", "w", stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", a+i, b+i);
    adj[a[i]].push_back(i);
    adj[b[i]].push_back(i);
  }
  memset(vis, 0, sizeof vis);
  memset(die, 0, sizeof die);
  list < int > ans, rev;
  int u = a[adj[1][0]] ^ b[adj[1][0]] ^ 1;
  ans.push_back(1);
  ans.push_back(u);
  used[1] = used[u] = 1;
  die[adj[1][0]] = 1;
  auto it = ans.begin();
  while (1) {
    if (it == ans.end())
      break;
    auto nx = it;
    nx++;
    if (nx == ans.end())
      break;
    used[*it] = 0;
    bool res = dfs(it, nx, ans);
    used[*it] = 1;
    dfs2(*it);
    if (!res)
      it++;
  }
  rev.push_back(u);
  rev.push_back(1);
  it = rev.begin();
  while (1) {
    if (it == rev.end())
      break;
    vis[*it] = 0;
    auto nx = it;
    nx++;
    if (nx == rev.end())
      break;
    vis[*nx] = 1;
    used[*it] = 0;
    bool res = dfs(it, nx, rev);
    used[*it] = 1;
    dfs2(*it);
    if (!res)
      it++;
  }
  // it = ans.begin();
  // while (it != ans.end()) {
  //   cerr << *it << endl;
  //   it++;
  // }
  // it = rev.begin();
  // while (it != rev.end()) {
  //   cerr << *it << endl;
  //   it++;
  // }
  auto ia = ans.begin();
  ia++;
  auto ir = rev.end();
  ir--; ir--;
  if (*ir < *ia) {
    ir = rev.end();
    ir--;
    while (1) {
      printf("%d ", *ir);
      if (ir == rev.begin())
        break;
      ir--;
    }
    ia = ans.end();
    ia--; ia--;
    while (ia != ans.begin()) {
      printf("%d ", *ia);
      ia--;
    }
  }
  else {
    ia = ans.begin();
    while (ia != ans.end()) {
      printf("%d ", *ia);
      ia++;
    }
    ir = rev.begin();
    ir++;
    while (ir != rev.end()) {
      if (*ir == 1)
        break;
      printf("%d ", *ir);
      ir++;
    }
  }
  printf("\n");
  return 0;
}