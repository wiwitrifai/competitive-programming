#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = 400*N;
pair<int, pair<int, int> > ed[N];
vector< pair<int, int> > adj[N];

int n, m, p[N];
char s[M];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int u, int v) {
  if((u = find(u)) == (v = find(v)))
    return false;
  if(p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}
vector< pair<int, long long > > ans;

int dfs(int u, int p = -1) {
  int sz = 1;
  for(auto nx : adj[u]) if(p != nx.first) {
    int res = dfs(nx.first, u);
    sz += res;
    ans.push_back(make_pair(nx.second, 1LL*(n-res)*res));
  }
  return sz;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ed[i] = make_pair(c, make_pair(a-1, b-1));
  }
  sort(ed, ed+m);
  memset(p, -1, sizeof p);
  for(int i = 0; i<m; i++) {
    int u = ed[i].second.first, v = ed[i].second.second;
    if(merge(u, v)) {
      int w = ed[i].first;
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
  }
  dfs(0);
  sort(ans.begin(), ans.end());
  long long cnt = 0, cur = 0;
  int id = M-1;
  s[id] = '\0';
  for(int i = 0; i<ans.size(); i++) {
    while(cur<ans[i].first) {
      cur++;
      s[--id] = (cnt & 1) + '0';
      cnt >>= 1;
    }
    cnt += ans[i].second;
  }
  while(cnt) {
    s[--id] = (cnt & 1) + '0';
    cnt >>= 1;
  }
  printf("%s\n", s+id);
  return 0;
}