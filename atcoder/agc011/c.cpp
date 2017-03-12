#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector< int > g[N];
bool used[N];
int a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(used, 0, sizeof used);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    used[u] = used[v] = 1;
  }
  set< int > st;
  for (int i = 0; i < n; i++) {
    a[i] = i;
    b[i] = N;
    st.insert(i);
  }
  while (!st.empty()) {
    auto it = st.begin();
    int u = *it; st.erase(it);
    for (int v : g[u]) {
      if (b[v] <= a[u] && a[v] <= b[u]) continue;
      b[v] = min(b[v], a[u]);
      a[v] = min(a[v], b[u]);
      st.insert(v);
    }
  }
  long long cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += !used[i];
  long long ans = cnt * (n-cnt) * 2 + cnt * cnt;
  int same = 0, la = 0, lb = 0, all = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) continue;
    if (min(a[i], b[i]) == i) all++;
    la += a[i] == i;
    lb += b[i] == i;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) continue;
    if (min(a[i], b[i]) != i) continue;
    if (a[i] == b[i]) {
      if (a[i] != i) continue;
      ans += all;
    }
    else {
      if (a[i] < b[i])
        ans += la;
      else
        ans += lb;
    }
  }
  printf("%lld\n", ans);
  return 0;
}