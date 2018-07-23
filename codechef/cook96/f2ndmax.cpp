#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> g[N];
int rev[N];
bool root[N], cand[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
      g[i].clear();
    fill(root, root+n, 1);
    fill(cand, cand+n, 1);
    fill(rev, rev+n, 0);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      ++rev[v];
      root[v] = 0;
    }
    for (int i = 0; i < n; ++i) {
      if (rev[i] > 1)
        cand[i] = 0;
      if (root[i]) continue;
      for (int v : g[i])
        cand[v] = 0;
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
      if (!root[i]) continue;
      assert(cand[i]);
      sort(g[i].begin(), g[i].end());
      g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
      int cnt = 0;
      for (int v : g[i]) {
        cnt += cand[v];
      }
      pq.push(-cnt);
    }
    int ans = 0;
    while (pq.size() > 1) {
      int u = -pq.top(); pq.pop();
      int v = -pq.top(); pq.pop();
      if (u > v) swap(u, v);
      ++v;
      pq.push(-v);
      ++ans;
    }
    int val = -pq.top();
    ans += max(val-1, 0);
    printf("%d\n", ans);
  }

  return 0;
}