#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

set<pair<int, int> > st;
int cnt = 0, unavail = 0;
set<int> ans;
int c[N], din[N];
vector<int> g[N], f[N];

int cntr = 0;

void del(int v) {
  ++cntr;
  assert(!(c[v] == -1 || c[v] == 2));
  st.erase(make_pair(din[v], v));
  for (int u : g[v]) {
    ++cntr;
    if (c[u] == 0 || c[u] == 1) {
      st.erase(make_pair(din[u], u));
      --din[u];
      st.insert(make_pair(din[u], u));
    }
  }
}

void rem(int v) {
  ++cntr;
  if (c[v] == -1)
    return;
  else if (c[v] == 1) {
    del(v);
    c[v] = 2;
  }
  else if (c[v] == 0) {
    ++unavail;
    --cnt;
    del(v);
    c[v] = -1;
  }
}

void can(int v) {
  ++cntr;
  if (c[v] == -1) {
    c[v] = 2;
    --unavail;
  }
  else if (c[v] == 1)
    return;
  else if (c[v] == 0) {
    --cnt;
    c[v] = 1;
  }
}

void direct(int v) {
  ++cntr;
  if (c[v] == 2)
    return;
  if (c[v] == -1)
    --unavail;
  else if (c[v] == 0)
    --cnt;
  if (c[v] == 0 || c[v] == 1)
    del(v);
  c[v] = 2;
  for (int u : g[v])
    can(u);
}

void add(int v) {
  ++cntr;
  assert(c[v] == 0 || c[v] == 1);
  if (c[v] == 0)
    --cnt;
  del(v);
  c[v] = 2;
  for (int u : g[v]) {
    direct(u);
  }
  for (int u : f[v]) {
    rem(u);
  }
  ans.insert(v);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    f[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
    g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    sort(f[i].begin(), f[i].end());
    f[i].erase(unique(f[i].begin(), f[i].end()), f[i].end());
  }
  cnt = n;
  for (int i = 0; i < n; ++i) {
    din[i] = f[i].size();
    st.insert(make_pair(din[i], i));
  }
  while (cnt + unavail > 0) {
    auto it = st.begin();
    add(it->second);
  }
  printf("%d\n", (int)ans.size());
  for (int x : ans)
    printf("%d ", x+1);
  printf("\n");
  cerr << cntr << endl;
  return 0;
}