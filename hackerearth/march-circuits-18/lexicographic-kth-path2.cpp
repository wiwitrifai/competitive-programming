#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long inf = 1e18 + 9;
 
vector<pair<int, char> > g[N];
 
int dist[N];
long long cnt[N], cnt2[N];
vector<int> active[N];
 
long long bigmul(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (inf / a < b) return inf;
  return min(a * b, inf);
}
long long bigadd(long long a, long long b) {
  return min(a + b, inf);
}
 
int main() {
  int n, m;
  long long k;
  scanf("%d %d %lld", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int u, v;
    char c;
    scanf("%d %d %c", &u, &v, &c);
    --u, --v;
    g[u].emplace_back(v, c);
    g[v].emplace_back(u, c);
  }
  queue<int> que;
  memset(dist, -1, sizeof dist);
  dist[n-1] = 0;
  cnt[n-1] = 1;
  que.push(n-1);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (auto it : g[v]) {
      int u = it.first;
      char c = it.second;
      if (dist[u] == -1) {
        dist[u] = dist[v] + 1;
        cnt[u] = cnt[v];
        que.push(u);
      }
      else if (dist[u] == dist[v] + 1) {
        cnt[u] = bigadd(cnt[u], cnt[v]);
      }
    }
  }
  if (cnt[0] < k) {
    puts("-1");
    return 0;
  }
  active[dist[0]].push_back(0);
  cnt2[0] = 1;
  for (int d = dist[0]; d > 0; --d) {
    char s = 'a';
    while (s < 'z') {
      long long cur = 0;
      for (int v : active[d]) {
        for (auto it : g[v]) if (it.second == s && dist[it.first] == d-1) {
          cur = bigadd(cur, bigmul(cnt2[v], cnt[it.first]));
        }
      }
      if (cur < k) {
        k -= cur;
        ++s;
      }
      else
        break;
    }
    printf("%c", s);
    for (int v : active[d]) {
      for (auto it : g[v]) if (it.second == s && dist[it.first] == d-1) {
        int u = it.first;
        if (cnt2[u] == 0)
          active[d-1].push_back(u);
        cnt2[u] = bigadd(cnt2[u], cnt2[v]);
      }
    }
  }
  printf("\n");
  return 0;
}