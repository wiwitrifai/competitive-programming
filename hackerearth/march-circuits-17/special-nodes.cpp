#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector< int > g[N];
vector< int > best[N], sbest[N], dim[N];
int ans, n;
int deep[N], dm[N], pp[N], dup[N];
void pre(int v = 0, int par = -1) {
  deep[v] = 0;
  dm[v] = 0;
  pp[v] = par;
  for (int u : g[v]) if (u != par) {
    pre(u, v);
    dm[v] = max(dm[v], deep[v] + deep[u] + 1);
    dm[v] = max(dm[v], dm[u]);
    deep[v] = max(deep[v], deep[u] + 1); 
  }
}
bool live[N];
pair< int, int > go(int v, int par = -1) {
  pair< int, int > ret(0, v);
  if (v == -1) return ret;
  for (int u : g[v]) if (u != par && live[u]) {
    pair< int, int > res = go(u, v);
    res.first++;
    ret = max(ret, res);
  }
  return ret;
}
pair< int, int >  getdim(int v) {
  live[v] = 0;
  pair< int, int > res = go(pp[v]);
  int d = res.first;
  res = go(res.second);
  live[v] = 1;
  return make_pair(res.first, d);
}
int vans, dist, dist2;
void dfs(int v = 0, int par = -1, int d = 0, int depth = -1) {
  int b = 0, sb = 0, dd = 0;
  if (par != -1) {
    auto it = getdim(v);
    d = it.first, depth = it.second;
  }
  dup[v] = depth;
  for (int i = 0; i < min(depth, deep[v]); i++) {
    int cur = max(max(depth-i, d-(depth-i)), max(deep[v]-i, dm[v]-deep[v]+i));
    if (cur < ans) {
      ans = cur;
      vans = v;
      dist = i;
      dist2 = i;
    } 
    if (i + 1 <= depth) {
      cur = max(max(depth-i-1, d-(depth-i-1)), max(deep[v]-i, dm[v]-deep[v]+i));
      if (cur < ans) {
        ans = cur;
        vans = v;
        dist = i;
        dist2 = i+1;
      }
    }

    if (i + 1 <= deep[v]) {
      cur = max(max(depth-i, d-(depth-i)), max(deep[v]-i-1, dm[v]-deep[v]+i+1));
      if (cur < ans) {
        ans = cur;
        vans = v;
        dist = i+1;
        dist2 = i;
      }
    }
  }
  for (int u : g[v]) if (u != par) {
    best[v].push_back(b);
    sbest[v].push_back(sb);
    dim[v].push_back(dd);
    if (deep[u] + 1 > b) {
      sb = b;
      b = deep[u] + 1;
    }
    else if (deep[u] + 1 > sb)
      sb = deep[u] + 1;
    dd = max(dd, dm[u]);
  }
  b = depth + 1, sb = 0, dd = d;
  for (int i = (int)g[v].size()-1, j = (int)best[v].size()-1; i >= 0; i--) {
    int u = g[v][i];
    if (u == par) continue;
    int bnow = b, sbnow = sb, x = best[v][j];
    if (x > bnow)
      sbnow = bnow, bnow = x;
    else if (x > sbnow)
      sbnow = x;
    x = sbest[v][j];
    if (x > bnow)
      sbnow = bnow, bnow = x;
    else if (x > sbnow)
      sbnow = x;
    int dnow = max(dd, max(dim[v][j], bnow + sbnow));
    dfs(u, v, dnow, bnow);

    if (deep[u] + 1 > b) {
      sb = b;
      b = deep[u] + 1;
    }
    else if (deep[u] + 1 > sb)
      sb = deep[u] + 1;
    dd = max(dd, dm[u]);
    j++;
  }
}

int main() {
  memset(live, 1, sizeof live);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vans = -1;
  pre();
  ans = deep[0];
  dfs();
  cout << ans << endl;
  int a = vans, d = dist;
  while (d--) {
    for (int u : g[a]) if (u != pp[a])
      if (deep[u] + 1 == deep[a]) {
        a = u;
        break;
      }
  }
  d = dist2;
  int last = vans, b = pp[vans], dcur = dup[vans];
  while (d) {
    if (pp[b] >= 0 && deep[pp[b]] == dcur-1) {
      last = b;
      b = pp[b];
      d--;
      dcur--;
    }
    else
      break;
  }
  while (d--) {
   for (int u : g[a]) if (u != pp[b] && u != last)
      if (deep[u] + 1 == deep[b]) {
        b = u;
        break;
      } 
  }
  cout << a + 1 << " " << b + 1 << endl;
  return 0;
}