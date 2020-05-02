#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7, L = 13, LM = (1 << L) - 1;
const int MAXK = 100;

vector<vector<int>> graph;

int main() {
  auto startt = clock();
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> ab(m), w(m);
  graph.resize(n);
  int s, t;
  scanf("%d %d", &s, &t);
  --s, --t;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d %d", &u, &v, &w[i]);
    --u, --v;
    ab[i] = u ^ v;
    graph[u].push_back(i);
    graph[v].push_back(i);
  }
  vector<bool> isb(n, true);
  for (int i = 0; i < k; ++i) {
    int u;
    scanf("%d", &u);
    --u;
    isb[u] = false;
  }
  vector<int> minb(n, inf);
  minb[s] = isb[s];
  queue<int> que, nxt;
  que.emplace(s);
  while (!que.empty() || !nxt.empty()) {
    if (que.empty()) {
      que.swap(nxt);
    }
    int v = que.front();
    que.pop();
    for (int e : graph[v]) {
      int u = ab[e] ^ v;
      if (minb[u] >= inf) {
        minb[u] = minb[v] + isb[u];
        if (isb[u])
          nxt.emplace(u);
        else
          que.emplace(u);
      }
    }
  }
  k = min(n-k, MAXK);
  vector<vector<int>> dist(n, vector<int>(k+1, inf));
  dist[s][0] = 0;
  vector<vector<bool>> inque(n, vector<bool>(k+1, false));
  inque[s][0] = true;
  priority_queue<pair<int, int>> pq;
  assert(que.empty());
  pq.emplace(0, s << L);
  while (!pq.empty() && (double)(clock() - startt) / CLOCKS_PER_SEC < 2.8) {
    int v = pq.top().second >> L, c = pq.top().second & LM, cur = -pq.top().first;
    pq.pop();
    // assert(inque[v][c]);
    // inque[v][c] = false;
    if (cur != dist[v][c])
      continue;
    c += minb[v];
    for (int e : graph[v]) {
      int u = ab[e] ^ v;
      int cu = c + isb[u] - minb[u];
      assert(cu >= 0);
      if (cu > k) continue;
      int newdist = cur + w[e];
      if (dist[u][cu] > newdist) {
        dist[u][cu] = newdist;
        pq.emplace(-newdist, (u << L) | cu);
        inque[u][cu] = true;
      }
    }
  }
  long long best = 1e18;
  int ans = -1;
  for (int i = 0; i <= k; ++i) {
    if (dist[t][i] >= inf) continue;
    int c = minb[t] + i;
    if (1LL * dist[t][i] * c < best) {
      ans = i;
      best = 1LL * dist[t][i] * c;
    }
  }
  assert(ans != -1);
  int now = t;
  vector<int> answer;
  while (now != s || ans != 0) {
    bool found = false;
    for (int e : graph[now]) {
      int u = now ^ ab[e];
      int c = ans + minb[now] - minb[u] - isb[now];
      if (c < 0 || c > k) continue;
      if (dist[u][c] + w[e] == dist[now][ans]) {
        answer.emplace_back(e);
        now = u;
        ans = c;
        found = true;
        break;
      }
    }
    assert(found);
  }
  reverse(answer.begin(), answer.end());
  printf("%d\n", (int)answer.size());
  for (int e : answer) {
    printf("%d\n", e+1);
  }
  return 0;
}
