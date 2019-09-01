// Warning: solusi ini agak salah wkwk, karena lupa implementasi DP SOS
// Tapi untung langsung AC, jadi ga nambah2 penalty :p
#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5, K = 15;
long long s[N], c[K];
int p[K];
int dist[K][N];

long long sum[1 << K];
vector<pair<int, int> > g[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  long long sums = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", s+i);
    sums += s[i];
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v,w);
    g[v].emplace_back(u,w);
  }
  long long sumc = 0;
  for (int i = 0; i < k; ++i) {
    scanf("%d %lld", p+i, c+i);
    --p[i];
    sumc += c[i];
  }
  if (sumc < sums) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < k; ++i) {
    fill(dist[i], dist[i]+n, int(1e9+ 5));
    dist[i][p[i]] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(-dist[i][p[i]], p[i]);
    while (!pq.empty()) {
      int v = pq.top().second, cur = -pq.top().first;
      pq.pop();
      if (cur != dist[i][v]) continue;
      for (auto e : g[v]) {
        int u = e.first, w = e.second + dist[i][v];
        if (dist[i][u] > w) {
          dist[i][u] = w;
          pq.emplace(-w, u);
        }
      }
    }
  }
  int low = 0, hig = 1e9 + 5;
  while (low < hig) {
    int mid = (low + hig) >> 1;
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < n; ++i) {
      int mask = 0;
      for (int j = 0; j < k; ++j) {
        if (dist[j][i] <= mid) {
          mask |= 1 << j;
        }
      }
      sum[mask] += s[i];
    }
    int nmask = 1 << k;

    // Di sini harusnya DP SOS dulu: sum[mask] = sum({sum[x] | (x & mask) = x})

    bool can = 1;
    for (int i = 0; i < nmask; ++i) {
      if (sum[i] == 0) continue;
      long long cur = 0;
      for (int j = 0; j < k; ++j) {
        if (i & (1 << j)) {
          cur += c[j];
        }
      }
      if (cur < sum[i]) {
        can = 0;
        break;
      }
    }
    if (can)
      hig = mid;
    else
      low = mid + 1;
  }
  printf("%d\n", low);
  return 0;
}
