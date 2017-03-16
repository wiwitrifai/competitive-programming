#include<bits/stdc++.h>

using namespace std;

typedef pair<pair<int,int>,int> piii;
typedef pair<int,int> pii;

map<piii,set<piii>> n_g;
map<pii,set<pii>> f_g;
set<piii> s_node, n_vis;
set<pii> f_node, f_vis;

int DFS(piii p, piii l)
{
  if (n_vis.count(p) != 0) return 1;
  n_vis.insert(p);
  for (auto &u: n_g[p]) {
    if (u != l && DFS(u, p)) return 1;
  }
  return 0;
}

int F_DFS(pii p, pii l)
{
  if (f_vis.count(p) != 0) return 1;
  f_vis.insert(p);
  for (auto &u: f_g[p]) {
    if (u != l && F_DFS(u, p)) return 1;
  }
  return 0;
}

int main()
{
  int K;
  scanf("%d", &K);
  for (int i = 0; i < K; ++i) {
    int x1, y1, z1;
    int x2, y2, z2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
    piii n1 = make_pair(make_pair(x1, y1), z1);
    piii n2 = make_pair(make_pair(x2, y2), z2);
    n_g[n1].insert(n2);
    n_g[n2].insert(n1);
    s_node.insert(n1);
    s_node.insert(n2);
    pii fn1 = make_pair(x1, y1);
    pii fn2 = make_pair(x2, y2);
    if (fn1 != fn2) {
      f_g[fn1].insert(fn2);
      f_g[fn2].insert(fn1);
    }
    f_node.insert(fn1);
    f_node.insert(fn2);

  }
  int o, f = o = 0;
  for (auto &p: s_node) {
    if (n_vis.count(p) != 0) continue;
    o |= DFS(p, make_pair(make_pair(0,0),0));
  }
  for (auto &p: f_node) {
    if (f_vis.count(p) != 0) continue;
    f |= F_DFS(p, make_pair(0,0));
  }
  if (o) puts("True closed chains");
  else puts("No true closed chains");
  if (f) puts("Floor closed chains");
  else puts("No floor closed chains");
  return 0;
}