#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e17;
vector < pair< int, int > > adj[N];
vector< pair< long long, pair<int, int> > > longest[N];
vector< int > open[N];
long long tot[N];
int last;

long long dfs1(int v = 0, int par = -1) {
  for (auto it : adj[v]) if (it.first != par) {
    long long res = dfs1(it.first, v) + it.second;
    longest[v].emplace_back(res, it);
  }
  sort(longest[v].begin(), longest[v].end()); 
  if (longest[v].size() > 0)
    return longest[v][0].first;
  return 0;
}
void dfs2(int v = 0, int par = -1, long long depth = 0, int id = 0) {
  // cerr <<par << " " << v << endl;
  if (longest[v].size() == 0) {
    tot[id] = depth;
    // // cerr << v << " leave " << id << " " << depth << endl;
  }
  else {
    int sel = longest[v][0].second.first, w = longest[v][0].second.second;
    dfs2(sel, v, depth + w, id);
    for (auto it : longest[v]) {
      int u = it.second.first, w = it.second.second;
      if (u == sel || u == par) continue;
      open[id].push_back(++last);
      dfs2(u, v, w, last);
    }
  }
}
int val[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++)
    scanf("%d", val+i);
  sort(val, val+m);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  } 
  dfs1();
  last = 0;
  dfs2();
  sort(val, val+m);
  set< pair< long long, int > > st;
  st.insert({tot[0], 0});
  vector< long long > vc;
  while (!st.empty()) {
    auto it = st.begin();
    int id = it->second;
    vc.push_back(tot[id]);
    st.erase(it);
    for (int nx : open[id]) {
      st.insert({tot[nx], nx});
    }

  }
  long long ans = 0;
  int id = m-1;
  for (int i = (int)vc.size()-1; i > 0; i--) {
    ans += vc[i] * val[id];
    id--;
  }
  id = 0;
  ans += vc[0] * val[0];
  printf("%lld\n", ans);


  return 0;
}