#include <bits/stdc++.h>

using namespace std;

struct RevertableDsu {
  vector<int> p;
  vector<pair<int *, int>> history;

  RevertableDsu(int n = 0) : p(n, -1), history(0) {}
  void reset(int n) {
    p.assign(n, -1);
    history.clear();
  }
  int find(int x) {
    return p[x] < 0 ? x : find(p[x]);  
  }
  int count(int x) {
    return -p[find(x)];
  }
  void upd(int * var, int value) {
    history.emplace_back(var, *var);
    *var = value;
  }
  void revert(int version) {
    while ((int)history.size() > version) {
      auto it = history.back();
      history.pop_back();
      *it.first = it.second;
    }
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (count(u) > count(v))
      swap(u, v);
    upd(&p[v], p[v] + p[u]);
    upd(&p[u], v);
    return true;
  }
};

RevertableDsu dsu;
vector<int> queries, answers;

void divide_conquer(vector<tuple<int, int, int, int>> & lifetimes, int l, int r) {
  if (queries.empty() || queries.back() >= r)
    return;
  vector<tuple<int, int, int, int>> unmerged;
  int version = dsu.history.size();
  int mid = (l + r) >> 1;
  for (auto & it : lifetimes) {
    int u, v, start_time, finish_time;
    tie(u, v, start_time, finish_time) = it;
    if (start_time >= r || finish_time <= l) continue;
    if (start_time <= l && r <= finish_time)
      dsu.merge(u, v);
    else
      unmerged.push_back(it);
  }
  if (l + 1 == r) {
    assert(!queries.empty() && queries.back() == l);
    answers.push_back((dsu.count(1) - 2) / 2);
    queries.pop_back();
  }
  else {
    divide_conquer(unmerged, l, mid);
    divide_conquer(unmerged, mid, r);
  }
  dsu.revert(version);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  set<int> points;
  map<pair<int, int>, int> edges;
  points.insert(0);
  points.insert(n+1);
  edges[make_pair(1, (n+1)*2)] = -1;
  vector<tuple<int, int, int, int>> lifetimes;
  auto remove_edge = [&](int u, int v, int finish_time) {
    auto it = edges.find(make_pair(u, v));
    assert(it != edges.end());
    lifetimes.emplace_back(u, v, it->second, finish_time);
    edges.erase(it);
  };
  auto insert_edge = [&](int u, int v, int start_time) {
    auto it = edges.find(make_pair(u, v));
    assert(it == edges.end());
    edges[make_pair(u, v)] = start_time;
  };
  auto find_neighboors = [&](int u) {
    auto it = points.lower_bound(u);
    assert(it != points.end());
    int rig = *it;
    assert(it != points.begin());
    int lef = *(--it);
    return make_pair(lef * 2 + 1, rig * 2);
  };

  for (int i = 0; i < q; ++i) {
    int t, x, y;
    scanf("%d", &t);
    if (t != 3) {
      scanf("%d %d", &x, &y);
      if (x > y)
        swap(x, y);
    }
    if (t == 1) {
      assert(!points.count(x) && !points.count(y));
      auto e1 = find_neighboors(x);
      auto e2 = find_neighboors(y);
      insert_edge(2 * x, 2 * y + 1, i);
      insert_edge(2 * y, 2 * x + 1, i);
      insert_edge(e1.first, 2 * x, i);
      insert_edge(2 * y + 1, e2.second, i);
      remove_edge(e1.first, e1.second, i);
      if (e2 == e1) {
        insert_edge(2 * x + 1, 2 * y, i);
      }
      else {
        remove_edge(e2.first, e2.second, i);
        insert_edge(2 * x + 1, e1.second, i);
        insert_edge(e2.first, 2 * y, i);
      }
      points.insert(x);
      points.insert(y);
    }
    else if (t == 2) {
      points.erase(x);
      points.erase(y);
      auto e1 = find_neighboors(x);
      auto e2 = find_neighboors(y);
      remove_edge(2 * x, 2 * y + 1, i);
      remove_edge(2 * y, 2 * x + 1, i);
      remove_edge(e1.first, 2 * x, i);
      remove_edge(2 * y + 1, e2.second, i);
      insert_edge(e1.first, e1.second, i);
      if (e2 == e1) {
        remove_edge(2 * x + 1, 2 * y, i);
      }
      else {
        insert_edge(e2.first, e2.second, i);
        remove_edge(2 * x + 1, e1.second, i);
        remove_edge(e2.first, 2 * y, i);
      }
    }
    else
      queries.push_back(i);
  }
  for (auto e : edges) {
    lifetimes.emplace_back(e.first.first, e.first.second, e.second, q);
  }
  dsu.reset((n + 2) * 2);
  reverse(queries.begin(), queries.end());
  divide_conquer(lifetimes, 0, q);
  for (int x : answers) {
    printf("%d\n", x);
  }
  return 0;
}
