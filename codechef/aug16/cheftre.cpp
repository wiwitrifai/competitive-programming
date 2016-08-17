#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], p[N], lv[N];
vector< int > adj[N];

void dfs(int u) {
  for (int v : adj[u]) if (v != p[u]) {
    p[v] = u;
    lv[v] = lv[u] + 1;
    dfs(v);
  }
}

vector< int > get(int u, int v) {
  vector< int > l, r;
  int x, y;
  x = u; y = v;
  while (x != y) {
    if (lv[x] > lv[y]) {
      l.push_back(a[x]);
      x = p[x];
    }
    else {
      r.push_back(a[y]);
      y = p[y];
    }
  }
  l.push_back(a[x]);
  for (int i = (int)r.size()-1; i >= 0; i--)
    l.push_back(r[i]);
  return l;
}

void assign(int u, int v, vector< int > &va) {
  int l = 0, r = (int)va.size()-1;
  while (u != v) {
    if (lv[u] > lv[v]) {
      a[u] = va[l++];
      u = p[u];
    }
    else {
      a[v] = va[r--];
      v = p[v];
    }
  }
  a[u] = va[l];
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) 
    scanf("%d", a+i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  p[0] = 0;
  lv[0] = 0;
  dfs(0);
  while (q--) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);
    u--; v--;
    if (t == 1) {
      vector< int > val = get(u, v);
      assign(v, u, val);
    }
    else {
      int x, y;
      scanf("%d %d", &x, &y);
      x--; y--;
      if (t == 2) {
        vector< int > res1 = get(u, v), res2 = get(x, y);
        bool ok = res1.size() == res2.size();
        assert(ok);
        for (int i = 0; i < res1.size() && ok; i++) {
          if (res1[i] != res2[i])
            ok = false;
        }
        puts(ok ? "Yes" : "No");
      }
      else {
        vector< int > res = get(u, v);
        assign(x, y, res);
      }
    }
  }
  return 0;
}