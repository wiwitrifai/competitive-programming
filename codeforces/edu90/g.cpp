#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = 3 * N;

vector<pair<int *, int>> logs;

void assign(int * ptr, int val) {
  logs.emplace_back(ptr, *ptr);
  *ptr = val;
}

void reset(int version) {
  while ((int)logs.size() > version) {
    auto it = logs.back();
    logs.pop_back();
    *it.first = it.second;
  }
}

int p[M];
int big[M];

int ans[N];
int find(int x) {
  return p[x] < 0 ? x : find(p[x]);
}

int merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return u;
  if (-p[u] > -p[v])
    swap(u, v);
  assign(&p[v], p[v] + p[u]);
  assign(&p[u], v);
  if (big[u] > big[v])
    assign(&big[v], big[u]);
  return v;
}


void dnc(vector<tuple<int, int, int>> & events, int l, int r, int maxi = -1) {
  int version = logs.size();
  for (auto & it : events) {
    int s, e, pos;
    tie(s, e, pos) = it;
    if (s <= l && r <= e) {
      int res = big[find(pos)];
      maxi = max(maxi, res);
      merge(res, res+1);
    }
  }
  if (r-l < 2) {
    ans[l] = maxi;
  } else {
    vector<tuple<int, int, int>> lef, rig;
    int mid = (l + r) >> 1;
    for (auto & it : events) {
      int s, e, pos;
      tie(s, e, pos) = it;
      if (s <= l && r <= e) continue;
      if (s < mid)
        lef.push_back(it);
      if (e > mid)
        rig.push_back(it);
    }
    dnc(lef, l, mid, maxi);
    dnc(rig, mid, r, maxi);
  }
  reset(version);
}

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  map<pair<int, int>, int> occur;
  vector<tuple<int, int, int>> events;
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    auto now = make_pair(x, y);
    auto it = occur.find(now);
    if (it == occur.end()) {
      occur[now] = i;
    } else {
      int s = y + abs(x - k);
      events.emplace_back(it->second, i, s);
      occur.erase(it);
    }
  }
  for (auto & it : occur) {
    int s = it.first.second + abs(it.first.first - k);
    events.emplace_back(it.second, m, s);
  }
  iota(big, big+M, 0);
  fill(p, p+M, -1);
  dnc(events, 0, m);
  for (int i = 0; i < m; ++i) {
    ans[i] = max(0, ans[i] - n);
    printf("%d\n", ans[i]);
  }
  return 0;
}
