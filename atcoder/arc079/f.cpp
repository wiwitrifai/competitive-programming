#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, p[N], cnt[N], add[N], c[N];

set<int> st[N];

int get(int v) {
  int val = 0;
  for (auto it = st[v].begin(); it != st[v].end(); it++) {
    if (*it > val) return val;
    val++;
  }
  return val;
}

bool cek(int v, int val) {
  return (get(v) == val);
}

int main() {
  scanf("%d", &n);memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    scanf("%d", p+i);
    p[i]--;
    cnt[p[i]]++;
  }
  queue< int > que;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      que.push(i);
    }
  } 
  while (!que.empty()) {
    int v = que.front(); que.pop();
    int val = get(v);
    st[p[v]].insert(val);
    cnt[p[v]]--;
    if (cnt[p[v]] == 0)
      que.push(p[v]);
  }
  memset(add, -1, sizeof add);
  memset(c, -1, sizeof c);
  int v = 0;
  for (int i = 0; i < n; i++) if (cnt[i] != 0) {
    v = i;
    break;
  }
  bool ok = 1;
  int u = v;
  c[v] = get(v);
  while (1) {
    // cerr << "cuk" << " " << u << endl;
    int pp = p[u];
    if (!st[pp].count(c[u])) {
      add[pp] = c[u];
      st[pp].insert(c[u]);
    }
    if (pp == v) {
      if (!cek(v, c[v]))
        ok = 0;
      break;
    }
    c[pp] = get(pp);
    u = pp;
  }
  if (ok) {
    puts("POSSIBLE");
    return 0;
  }
  u = v;
  while (1) {
    if (add[u] != -1)
      st[u].erase(add[u]);
    u = p[u];
    if (u == v)
      break;
  }
  if (add[v] != -1)
    st[v].erase(add[v]);
  memset(add, -1, sizeof add);
  memset(c, -1, sizeof c);
  ok = 1;
  u = v;
  int rem = get(v);
  st[v].insert(rem);
  c[v] = get(v);
  st[v].erase(rem);
  
  while (1) {
    int pp = p[u];
    if (!st[pp].count(c[u])) {
      add[pp] = c[u];
      st[pp].insert(c[u]);
    }
    if (pp == v) {
      if (!cek(v, c[v]))
        ok = 0;
      break;
    }
    c[pp] = get(pp);
    u = pp;
  }
  puts(ok ? "POSSIBLE" : "IMPOSSIBLE");
  return 0;
}