#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<int> g[N];
int sz[N], big[N];

void dfs1(int v) {
  sz[v] = 1;
  big[v] = -1;
  for (int u : g[v]){
    dfs1(u);
    sz[v] += sz[u];
    if (big[v] == -1 || sz[big[v]] < sz[u])
      big[v] = u;
  }
}

long long ans = 0;

bool used[N];
int cnt[N];

set<int> st;

void dfs3(int v) {
  if (!used[v]) {
    st.insert(v);
  }
  for (int u : g[v])
    dfs3(u);
}

void dfs2(int v) {
  for (int u : g[v]) {
    if (u == big[v]) continue;
    dfs2(u);
    st.clear();
  }
  if (big[v] != -1) {
    dfs2(big[v]);
  }
  st.insert(v);
  for (int u : g[v]) {
    if (u == big[v]) continue;
    dfs3(u);
  }
  while (cnt[v] > 0 && st.size() > 0) {
    auto it = st.end(); --it;
    assert(!used[*it]);
    --cnt[v];
    used[*it] = 1;
    ans += *it;
    st.erase(it);
  }
}


int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    for (int i = 1; i < n; ++i) {
      int p;
      scanf("%d", &p);
      g[p].push_back(i);
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < m; ++i) {
      long long c = 1LL * a *  i + b;
      c %= n;
      ++cnt[c];
    }
    dfs1(0);
    ans = 0;
    memset(used, 0, sizeof used);
    st.clear();
    dfs2(0);
    printf("Case #%d: %lld\n", tc,  ans);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}