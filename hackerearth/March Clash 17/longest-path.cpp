#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;

pair< int, int > add(pair< int, int > a, pair< int, int > b) {
  if (a.first < b.first)
    return b;
  if (a.first > b.first)
    return a;
  a.second += b.second;
  return a;
}

vector< int > g[N];
pair< int, long long > ans[N];

vector< pair< int, int > > child[N], sorted[N], pre[N];

pair< int, int > dfs(int u = 0, int par = -1) {
  pair< int, int > ret(0, 1);
  child[u].clear();
  for (int v : g[u]) if (v != par) {
    auto it = dfs(v, u);
    child[u].push_back(it);
    ret = add(ret, it);
  }
  ret.first += 1;
  return ret;
}
void dfs2(int u = 0, int par = -1, pair< int, int > vp = make_pair(0, 0)) {
  sorted[u] = child[u];
  pair< int , int > now = make_pair(0, 1);
  sorted[u].push_back(vp);
  sorted[u].push_back(now);
  sort(sorted[u].begin(), sorted[u].end());
  int len = sorted[u].size();
  if (sorted[u][len-1].first == sorted[u][len-2].first) {
    ans[u].first = sorted[u][len-1].first * 2 + 1;
    ans[u].second = 0;
    long long sum = 0;
    for (int i = len-1; i >= 0; i--) {
      if (sorted[u][i].first != sorted[u][len-1].first) break;
      ans[u].second += sum * sorted[u][i].second;
      sum += sorted[u][i].second;
    }
  }
  else {
    ans[u].first = sorted[u][len-1].first + sorted[u][len-2].first + 1;
    long long sum = 0;
    for (int i = len-2; i >= 0; i--) {
      if (sorted[u][i].first != sorted[u][len-2].first) break;
      sum += sorted[u][i].second;
    }
    ans[u].second = sum * sorted[u][len-1].second;
  }
  now = add(now, vp);
  pre[u].clear();
  for (int i = 0; i <  child[u].size(); i++) {
    pre[u].push_back(now);
    now = add(now, child[u][i]);
  }
  int id = (int)child[u].size()-1;
  now = make_pair(0, 0);
  for (int i = (int)g[u].size()-1; i >= 0; i--) {
    if (g[u][i] == par) continue;
    pair< int , int > cur = add(now, pre[u][id]);
    cur.first += 1;
    dfs2(g[u][i], u, cur);
    now = add(now, child[u][id]);
    id--;
  }

}


int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("1 1");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs();
  dfs2();
  for (int i = 0; i < n; i++)
    printf("%d %lld\n", ans[i].first, ans[i].second);
  return 0;
}