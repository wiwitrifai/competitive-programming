#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int x[N], y[N], ans[N];
int pos[N];
vector<int> g[N];
int d[2][N];
void bfs(int s, int res[N]) {
  queue<int> que;
  que.push(s);  
  res[s] = 0;
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int u : g[v]) if (res[u] < 0) {
      res[u] = res[v] + 1;
      que.push(u);
    }
  }
}
vector<int> qnow;

void solve(vector<int> & node, vector<pair<int ,int> > & edge, vector<int> que) {
  if (que.empty()) return;
  if (node.size() <= 3) {
    for (int i : que)
      ans[i] = (x[i] != y[i]);
    return;
  }
  for (int i = 0; i < node.size(); ++i)
    pos[node[i]] = i;
  int a = edge[0].first, b = edge[0].second;
  int n = node.size(), best = abs(pos[a]-pos[b]);
  best = min(best, n - best);
  for (auto it : edge) {
    int cur = abs(pos[it.first] - pos[it.second]);
    cur = min(cur, n - cur);
    if (cur > best)
      best = cur, a = it.first, b = it.second;
  }
  if (pos[a] > pos[b]) swap(a, b);
  vector<int> nodel, noder, quel, quer;
  vector<pair<int, int> > edgel, edger;
  auto kiri = [&] (int i) { return pos[a] <= i && i <= pos[b]; };
  auto kanan = [&] (int i) { return i <= pos[a] || pos[b] <= i; };
  for (int i = 0; i < node.size(); ++i) { 
    if (kiri(i))
      nodel.push_back(node[i]);
    if (kanan(i))
      noder.push_back(node[i]);
  }
  qnow.clear();
  for (int i : que) {
    if (!kanan(pos[x[i]]) && !kanan(pos[y[i]]))
      quel.push_back(i);
    else if (!kiri(pos[x[i]]) && !kiri(pos[y[i]]))
      quer.push_back(i);
    else
      qnow.push_back(i); 
  }
  if (qnow.size()) {
    for (int v : node) {
      d[0][v] = d[1][v] = -1;
      g[v].clear();
    }
    for (auto it : edge) {
      g[it.first].push_back(it.second);
      g[it.second].push_back(it.first);
    }
    for (int i = 0; i < node.size(); ++i) {
      int u = node[i], v = node[(i+1) % node.size()];
      g[u].push_back(v);
      g[v].push_back(u);
    }
    bfs(a, d[0]);
    bfs(b, d[1]);
    for (int i : qnow)
      ans[i] = min(d[0][x[i]] + d[0][y[i]], d[1][x[i]] + d[1][y[i]]);
  }
  for (auto it : edge) {
    if (!kanan(pos[it.first]) || !kanan(pos[it.second]))
      edgel.push_back(it);
    else if (!kiri(pos[it.first]) || !kiri(pos[it.second]))
      edger.push_back(it);
  }
  solve(nodel, edgel, quel);
  solve(noder, edger, quer);
}

void open(string name) {
#ifndef LOCAL
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
#endif
}

int main() {
  open("distance");
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > edge;
  for (int i = 0; i < n-3; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge.emplace_back(a, b);
  }
  vector<int> node;
  for (int i = 1; i <= n; ++i)
    node.push_back(i);
  int q;
  scanf("%d", &q);
  vector<int> que;
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", x+i, y+i);
    que.push_back(i);
  }
  solve(node, edge, que);
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}