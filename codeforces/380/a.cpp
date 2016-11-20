#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 56;
const int inf = 1e9 + 7;

int c[N], v[N], l[N], p[N];
long long sum[N];

int main() {
  int n, k, s, t;
  cin >> n >> k >> s >> t;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", c+i, v+i);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", p+i);
  }
  sort(p, p+k);
  int now = 0;
  for (int i = 0; i < k; i++) {
    l[i] = p[i]-now;
    now = p[i];
  }
  l[k++] = s-now;
  sort(l, l+k);
  sum[0] = 0;
  for (int i = 0; i < k; i++)
    sum[i+1] = sum[i]+l[i];
  int ans = inf;
  for (int i = 0; i < n; i++) {
    if (v[i] < l[k-1])
      continue;
    int id = upper_bound(l, l+k, v[i]/2) - l;
    long long cur = sum[id] + (sum[k]-sum[id]) * 3 - 1LL * v[i] * (k-id);
    // cerr << i << " " << c[i] << " " << v[i] << " " << cur << endl;
    if (cur <= t)
      ans = min(ans, c[i]);
  }
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}