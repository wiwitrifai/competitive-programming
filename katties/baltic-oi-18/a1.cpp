#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N], cyc[N], lv[N], id[N], ok[N], used[N];

char s[N];
map<string, int> mp;
int nodes = 0;

int getId(string st) {
  auto it = mp.find(st);
  if (it == mp.end())
    return mp[st] = nodes++;
  return it->second;
}

int getLv(int v) {
  if (cyc[v]) return 0;
  if (lv[v] > 0) return lv[v];
  return lv[v] = getLv(p[v]) + 1;
}

int main() {
  int n;
  scanf("%d", &n);
  nodes = 0;
  set<int> st;
  for (int i = 0; i < n; ++i) {
    int u, v;
    scanf("%s", s);
    u = getId(s);
    scanf("%s", s);
    v = getId(s);
    p[u] = v;
    st.insert(u);
  }
  assert(st.size() == n);
  assert(n == nodes);
  if (n & 1) {
    puts("-1");
    return 0;
  }
  fill(cyc, cyc+n, -1);
  for (int i = 0; i < n; ++i) {
    if (cyc[i] != -1) continue;
    int v = i;
    while (cyc[v] == -1) {
      cyc[v] = 0;
      v = p[v];
    }
    while (cyc[v] == 0) {
      cyc[v] = 1;
      v = p[v];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (p[p[i]] == i && p[i] != i) {
      used[i] = used[p[i]] = 1;
      ok[i] = ok[p[i]] = 1;
    }
  }
  for (int i = 0; i < n; ++i) id[i] = i;
  sort(id, id+n, [&](int l, int r) { return getLv(l) > getLv(r); });
  for (int i = 0; i < n; ++i) {
    int v = id[i];
    if (getLv(v) == 0) break;
    if (used[v] || used[p[v]]) continue;
    ok[v] = 1;
    used[p[v]] = 1;
    used[v] = 1;
  }
  for (int i = 0; i < n; ++i) {
    if (cyc[i] && used[i] == 1) {
      int v = i;
      while (used[v] <= 1) {
        if (used[v] == 0 && used[p[v]] == 0 && v != p[v]) {
          ok[v] = 1;
          used[v] = 2;
          used[p[v]] = 2;
          v = p[p[v]];
        }
        else {
          used[v] = 2;
          v = p[v];
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int v = i;
    while (!used[v]) {
      if (!used[p[v]] && v != p[v]) {
        used[v] = 1;
        ok[v] = 1;
        v = p[v];
      }
      used[v] = 1;
      v = p[v];
    }
  }
  int ans = n;
  for (int i = 0; i < n; ++i)
    ans -= ok[i];
  printf("%d\n", ans);
  return 0;
}