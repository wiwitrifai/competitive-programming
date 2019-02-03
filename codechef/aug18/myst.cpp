#include <bits/stdc++.h>

using namespace std;

const int N = 101, inf = 1e9;

int g[N][N], h[N][N];

multiset<int> gg[N], hh[N], ff[N];
int n;

int dist[N], pre[N];
bool can[N];

void bfs(int v) {
  fill(dist, dist+n, -1);
  fill(pre, pre+n, -1);
  dist[v] = 0;
  queue<int> que;
  que.push(v);
  while (!que.empty()) {
    v = que.front(); que.pop();
    for (int u : gg[v]) {
      if (dist[u] + 1) continue;
      dist[u] = dist[v] + 1;
      pre[u] = v;
      que.push(u);
    }
  }
}

vector<pair<int, int> > ans;
int calc(int u, int v) {
  auto it = gg[u].find(v);
  assert(it != gg[u].end());
  gg[u].erase(it);
  bfs(u);
  int ret = inf;
  for (int x : hh[v]) {
    if (dist[x] == -1) continue;
    ret = min(ret, dist[x]);
  }
  gg[u].insert(v);
  return ret;
}
int move(int u, int v) {
  auto it = gg[u].find(v);
  assert(it != gg[u].end());
  gg[u].erase(it);
  bfs(u);
  int w = -1;
  for (int x : hh[v]) {
    if (dist[x] == -1) continue;
    if (w == -1 || dist[w] > dist[x])
      w = x;
  }
  if (w == -1) {
    gg[u].insert(v);
    return -1;
  }
  gg[w].insert(v);
  it = hh[v].find(w);
  assert(it != hh[v].end());
  hh[v].erase(it);
  it = ff[u].find(v);
  ff[u].erase(it);
  int now = w;
  vector<int> step;
  --g[u][v];
  --h[w][v];
  while (now != u) {
    step.push_back(now);
    now = pre[now];
  }
  reverse(step.begin(), step.end());
  for (int x : step) {
    ans.emplace_back(x, v);
  }
  return w;
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      gg[i].clear(), hh[i].clear(), ff[i].clear();
    memset(g, 0, sizeof g);
    memset(h, 0, sizeof h);
    for (int i = 0; i < n; ++i) {
      int b;
      scanf("%d", &b);
      for (int j = 0; j < b; ++j) {
        int v;
        scanf("%d", &v); --v;
        ++g[v][i];
        gg[v].insert(i);
        ff[v].insert(i);
      }
      for (int j = 0; j < b; ++j) {
        int v;
        scanf("%d", &v); --v;
        ++h[v][i];
        hh[i].insert(v);
      }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int d = min(h[i][j], g[i][j]);
        g[i][j] -= d;
        h[i][j] -= d;
        while (d--) {
          auto it = hh[j].find(i);
          hh[j].erase(it);
          it = ff[i].find(j);
          ff[i].erase(it);
        }
      }
      sum += ff[i].size();
    }
    int v = 0;
    ans.clear();
    fill(can, can+n, true);
    vector<int> cannot;
    while (sum > 0) {
      if (ff[v].empty() || !can[v]) {
        bfs(v);
        int u = -1;
        for (int i = 0; i < n; ++i) {
          if (ff[i].empty() || !can[i]) continue;
          if (u == -1 || dist[u] > dist[i])
            u = i;
        }
        assert(u != -1);
        int now = u;
        vector<int> step;
        while (now != v) {
          step.push_back(now);
          now = pre[now];
        }
        reverse(step.begin(), step.end());
        for (int x : step) {
          ans.emplace_back(x, -1);
        }
        v = u;
      }
      bool ok = 0;
      int best = -1, cur = inf;
      for (int u : ff[v]) {
        int res = calc(v, u);
        if (cur > res)
          best = u, cur = res;
      }
      if (best == -1) {
        can[v] = false;
        cannot.push_back(v);
      }
      else {
        v = move(v, best);
        assert(v != -1);
        --sum;
        for (int u : cannot)
          can[u] = true;
        cannot.clear();
      }
    }
    printf("%d\n", (int)ans.size());
    for (auto it : ans)
      printf("%d %d\n", it.first+1, it.second+1);
  }
  return 0;
}