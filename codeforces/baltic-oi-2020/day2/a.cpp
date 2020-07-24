#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> g[N];

int val[N], vis[N], col[N];

vector<pair<int, int>> edges;
vector<int> nodes[2];

bool findOddCycle(int v, int c) {
  if (vis[v]) {
    return (c != col[v]);
  }
  vis[v] = 1;
  col[v] = c;
  nodes[c].push_back(v);
  for (auto & e : g[v]) {
    edges.emplace_back(e);
    bool found = findOddCycle(e.first, c^1);
    if (found)
      return true;
    edges.pop_back();
  }
  return false;
}

bool apply(int v, int s, int c) {
  if (vis[v] == c) {
    return (val[v] == s);
  }

  vis[v] = c;
  val[v] = s;
  for (auto & e : g[v]) {
    bool ok = apply(e.first, e.second - s, c);
    if (!ok)
      return false;
  }
  return true;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    w *= 2;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    nodes[0].clear();
    nodes[1].clear();
    edges.clear();
    edges.emplace_back(i, -1);
    bool found = findOddCycle(i, 0);
    if (found) {
      int last = edges.back().first;
      int sum = edges.back().second;
      edges.pop_back();
      int sign = -1;
      while (last != edges.back().first) {
        sum += sign * edges.back().second;
        sign = -sign;
        edges.pop_back();
      }
      sum /= 2;
      bool ok = apply(last, sum, 2);
      if (!ok) {
        puts("NO");
        return 0;
      }
    } else {
      bool ok = apply(i, 0, 2);
      if (!ok) {
        puts("NO");
        return 0;
      }
      int offset = 0;
      long long sum = 0;
      vector<int> vals;
      long long sumright = 0, sumleft = 0;
      for (int j = 0; j < 2; ++j) {
        for (int v : nodes[j]) {
          int cur = val[v];
          if (col[v] != col[i])
            cur = -cur;
          vals.emplace_back(cur);
          sum += abs(cur);
          sumright += cur;
        }
      }
      sort(vals.begin(), vals.end());
      for (int j = 0; j < (int)vals.size(); ++j) {
        long long cntleft = j, cntright = (int)vals.size() - j;
        long long cur = (sumright - cntright * vals[j]) + (cntleft * vals[j] - sumleft);
        if (sum > cur) {
          sum = cur;
          offset = -vals[j];
        }
        sumright -= vals[j];
        sumleft += vals[j];
      }
      apply(i, offset, 3);
    }
  }
  puts("YES");
  for (int i = 0; i < n; ++i) {
    int x = abs(val[i]) / 2;
    if (val[i] < 0)
      printf("-");
    printf("%d.%d%c", x, (val[i] & 1) ? 5 : 0, i+1 == n ? '\n' : ' ');
  }
  return 0;
}
