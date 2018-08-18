#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;;

int w[105];
int cnt[1 << 12], sum[1 << 12];
int ans[N];
vector<int> que[105];
int v[N];

int n, m, q;
char s[105];
int read_mask() {
  scanf("%s", s);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1')
      ret |= 1 << i;
  }
  return ret;
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", w+i);
  vector<pair<int, int> > cost;
  int nn = 1 << n;
  for (int i = 0; i < nn; ++i) {
    int val = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) continue;
      val += w[j];
    }
    cost.emplace_back(val, i);
  }
  for (int i = 0; i < m; ++i) {
    int mask = read_mask();
    ++cnt[mask];
  }
  for (int i = 0; i < q; ++i) {
    v[i] = read_mask();
    int k;
    scanf("%d", &k);
    que[k].push_back(i);
  }
  sort(cost.begin(), cost.end());
  for (int k = 0, j = 0; k <= 100; ++k) {
    if (que[k].empty()) continue;
    while (j < cost.size() && cost[j].first <= k) {
      int now = cost[j].second;
      for (int i = 0; i < nn; ++i) {
        sum[i] += cnt[i^now];
      }
      ++j;
    }
    for (int z : que[k])
      ans[z] = sum[v[z]];
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}