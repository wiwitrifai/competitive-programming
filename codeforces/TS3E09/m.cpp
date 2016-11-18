#include <bits/stdc++.h>

using namespace std;

const int N = 10110;
int n;
long long ans[N];
bool found[N], contra[N];
vector< int > adj[N];
map< string, int > mp;
char str[N], str2[N];
int v1[N], v2[N], z[N];
int vis[N], col[N];
long long cost[N];


int dfs(int v, int c = 0, long long cur = 0) {
  if (col[v] >= 0 && c != col[v]) {
    assert(((cur-cost[v]) & 1) == 0);
    if (c)
      ans[v] = (cur - cost[v]) / 2;
    else
      ans[v] = (cost[v] - cur) / 2;
    return v;
  }
  col[v] = c;
  for (int i : adj[v]) if (!vis[i]) {
    vis[i] = 1;
    int u = v1[i] + v2[i] - v;
    int res = dfs(u, !c, cur + (c ? -z[i] : z[i]));
    if (res >= 0)
      return res;
  }
  return -1;
}

bool upd(int u, int cur) {
  if (found[u]) {
    if (ans[u] != cur) {
      return false;
    }
    else
      return true;
  }
  found[u] = true;
  ans[u] = cur;
  for (int i : adj[u]) {
    int v = v1[i] + v2[i] - u;
    if (!upd(v, z[i]-cur))
      return false;
  }
  return true;
}

void visit(int u) {
  if (vis[u])
    return;
  vis[u] = 1;
  for (int i : adj[u]) {
    int v = v1[i] ^ v2[i] ^ u;
    visit(v);
  }
}

void upd_contra(int u) {
  // cerr << "contra " << u << endl;
  contra[u] = true;
  for (int i : adj[u]) {
    int v = v1[i] + v2[i] - u;
    if (!contra[v])
      upd_contra(v);
  }
}
bool get(int u, int t, int & res, int cur = 0) {
  if (t == u) {
    res = cur;
    return true;
  }
  for (int i : adj[u]) if (!vis[i]) {
    vis[i] = 1;
    int v = v1[i] + v2[i] - u;
    if (get(v, t, res, z[i]-cur))
      return true;
  }
  return false;
}

int main() {
  int m;
  scanf("%d", &m);
  n = 0;
  for (int i = 0; i < m; i++) {
    scanf("%s", str);
    int off = 0;
    while (str[off] >= 'a' && str[off] <= 'z') off++;
    if (mp.count(string(str, str+off)))
      v1[i] = mp[string(str, str+off)];
    else
      v1[i] = mp[string(str, str+off)] = n++; 
    // cerr << string(str, str+off) << endl;
    int off2 = ++off;
    while (str[off2] >= 'a' && str[off2] <= 'z') off2++;
    if (mp.count(string(str+off, str+off2)))
      v2[i] = mp[string(str+off, str+off2)];
    else
      v2[i] = mp[string(str+off, str+off2)] = n++;
    adj[v1[i]].push_back(i);
    adj[v2[i]].push_back(i);
    int len = strlen(str);
    z[i] = stoi(string(str+off2+1, str+len)) * 2;
  }
  memset(col, -1, sizeof col);
  memset(found, 0, sizeof found);
  for (int i = 0; i < n; i++) if (col[i] == -1 && !found[i] && !contra[i]) {
    int res = dfs(i);
    if (res < 0)
      continue;
    if (upd(res, ans[res]))
      continue;
    // cerr << res << endl;
    upd_contra(res);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%s", str);
    int off = 0;
    while (str[off] >= 'a' && str[off] <= 'z') off++;
    string s1 = string(str, str+off);
    int off2 = ++off;
    while (str[off2]) off2++;
    string s2 = string(str+off, str + off2);

    int u, v;
    if (!mp.count(string(s1)) || !mp.count(string(s2)))
      continue;
    u = mp[string(s1)];
    v = mp[string(s2)];
    // cerr << u << " " << v << endl;
    if (contra[u] || contra[v])
      continue;
    if (found[u] != found[v])
      continue;
    if (found[u]) {
      memset(vis, 0, sizeof vis);
      visit(u);
      if (!vis[v])
        continue;
      printf("%s+%s=%d\n", s1.c_str(), s2.c_str(), (ans[u] + ans[v])/2);
    }
    else {
      if (u == v)
        continue;
      // cerr << col[u] << " | " << col[v] << endl;
      if (col[u] == col[v])
        continue;
      memset(vis, 0, sizeof vis);
      int anss = 0;
      if (get(u, v, anss, 0))
        printf("%s+%s=%d\n", s1.c_str(), s2.c_str(), anss/2);
    }
  }
  return 0;
}