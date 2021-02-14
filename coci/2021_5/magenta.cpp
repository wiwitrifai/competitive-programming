#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> g;

vector<int> path, edge;

bool dfs(int v, int t, int par = -1) {
  path.push_back(v);
  if (v == t)
    return true;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par) continue;
    edge.push_back(e.second);
    if (dfs(u, t, v)) {
      return true;
    }
    edge.pop_back();
  }
  path.pop_back();
  return false;
}

int find(int v, int par, int mask, int other, int forbidden) {
  int ret = 1;
  for (auto & e : g[v]) {
    int u = e.first;
    if (u == par || (e.second & mask) == 0 || u == forbidden) continue;
    int res = find(u, v, mask, other, forbidden);
    if (res < 0)
      return res;
    if (res >= 2 && (e.second & other) == 0)
      return -1;
    ret += res;
  }
  return ret;
}

void win() {
  cout << "Paula\n";
  exit(0);
}

void lose() {
  cout << "Marin\n";
  exit(0);
}

void draw() {
  cout << "Magenta\n";
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  --a, --b;
  g.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    int mask = 0;
    if (s != "plava")
      mask |= 2;
    if (s != "crvena")
      mask |= 1;
    --u, --v;
    g[u].emplace_back(v, mask);
    g[v].emplace_back(u, mask);
  }
  auto get_mask = [&](int v, int par = -1) {
    int mask = 0;
    for (auto & e : g[v]) {
      if (e.first == par) continue;
      mask |= e.second;
    }
    return mask;
  };
  if ((get_mask(a, b) & 1) == 0) {
    lose();
  }
  if ((get_mask(b) & 2) == 0) {
    win();
  }
  dfs(a, b, -1);
  if (path.size() & 1) {
    int mid = path.size() / 2;
    int pos = path.size() - 1;
    while (pos-1 > mid && (edge[pos-1] & 2) != 0) {
      --pos;
    }
    for (int i = 0; i < min(pos, (int)edge.size()-1); ++i) {
      if ((edge[i] & 1) == 0) {
        draw();
      }
    }
    if (find(path[pos], -1, 2, 1, path[mid]) < 0)
      draw();
    else
      win();
  } else {
    int mid = path.size() / 2;
    int pos = 0;
    while (pos + 1 < mid && (edge[pos] & 1) != 0) {
      ++pos;
    }
    for (int i = max(1, pos); i < (int)edge.size(); ++i) {
      if ((edge[i] & 2) == 0) {
        draw();
      }
    }
    if (find(path[pos], -1, 1, 2, path[mid]) < 0)
      draw();
    else
      lose();
  }
  return 0;
}
