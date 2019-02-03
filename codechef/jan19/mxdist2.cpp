#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 4;

pair<long long, long long> p[N];

long long dist(int a, int b) {
  long long dx = p[a].first - p[b].first, dy = p[a].second - p[b].second;
  return dx * dx + dy * dy;
}
int l[N], r[N];
long long ans[N], val[N];
vector<int> que[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = make_pair(x, y);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", l+i, r+i);
    --l[i], --r[i];
    que[l[i]].push_back(i);
  }
  for (int i = n-1; i >= 0; --i) {
    long long best = 0;
    for (int j = i+1; j < n; ++j) {
      long long cur = dist(i, j);
      if (best < cur)
        best = cur;
      if (val[j] < best)
        val[j] = best;
    }
    for (int x : que[i])
      ans[x] = val[r[x]];
  }
  for (int i = 0; i < q; ++i)
    printf("%lld\n", ans[i]);

  return 0;
}