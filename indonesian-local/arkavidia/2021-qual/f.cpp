#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair<int, int>> g[N];
long long dist[N];

void dfs(int v, int par = -1, long long depth = 0) {
  dist[v] = depth;
  for (auto & e : g[v]) {
    int u, w;
    tie(u, w) = e;
    if (u == par) continue;
    dfs(u, v, depth + w);
  }
}

bool mark[N];

void mark_path(int v, int leaf, int par = -1) {
  mark[v] = v == leaf;
  for (auto & e : g[v]) {
    int u, w;
    tie(u, w) = e;
    if (u == par) continue;
    mark_path(u, leaf, v);
    mark[v] |= mark[u];
  }
}

int to[N];
void find_path(int v, int par = -1) {
  for (auto & e : g[v]) {
    int u, w;
    tie(u, w) = e;
    if (u == par) continue;
    find_path(u, v);
    if (to[u] == -1) continue;
    if (to[v] == -1 || u > to[v])
      to[v] = u;
  }
}

vector<int> ans;
void construct_ans(int v, int par = -1) {
  ans.push_back(v);
  sort(g[v].begin(), g[v].end());
  for (auto & e : g[v]) {
    int u, w;
    tie(u, w) = e;
    if (u == par || mark[u]) continue;
    construct_ans(u, v);
    ans.push_back(v);
  }
  for (auto & e : g[v]) {
    int u, w;
    tie(u, w) = e;
    if (u == par || !mark[u]) continue;
    construct_ans(u, v);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  long long total = 0;
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    total += w;
  }
  dfs(0);
  int leaf = max_element(dist, dist+n) - dist;
  dfs(leaf);
  int leaf2 = max_element(dist, dist+n) - dist;
  long long longest = dist[leaf2];
  int mid = -1;
  if ((longest & 1) == 0) {
    mark_path(leaf, leaf2);
    for (int i = 0; i < n; ++i) {
      if (mark[i] && dist[i] * 2LL == longest) {
        mid = i;
      }
    }
  }
  if (mid >= 0) {
    dfs(mid);
    vector<int> candidates;
    long long half = longest / 2;
    for (int i = 0; i < n; ++i) {
      if (dist[i] == half) {
        candidates.push_back(i);
      }
    }
    leaf = candidates[0];
    fill(to, to+n, -1);
    for (int v : candidates)
      to[v] = v;
    to[candidates[0]] = -1;
    find_path(mid);
    int now = mid;
    while (now != to[now]) {
      assert(to[now] >= 0);
      now = to[now];
    }
    leaf2 = now;
  }
  if (leaf > leaf2)
    swap(leaf, leaf2);
  mark_path(leaf, leaf2);
  construct_ans(leaf);
  while (!ans.empty() && ans.back() != leaf2)
    ans.pop_back();
  printf("%lld\n%d\n", total * 2LL - longest, (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i]+1, i+1 == (int)ans.size() ? '\n' : ' ');
  }
  return 0;
}
