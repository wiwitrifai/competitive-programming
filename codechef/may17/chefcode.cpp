#include <bits/stdc++.h>

using namespace std;

long long a[33];
long long mul(long long x, long long y, long long m) {
  if (y > m/x) return m+1;
  return x * y;
}

int main() {
  int t = 1;
  while (t--) {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++)
      scanf("%lld", a+i);
    int nn[2], off[2];
    nn[0] = n/2, nn[1] = n-nn[0];
    off[0] = 0, off[1] = nn[0];
    vector< long long > val[2];
    for (int j = 0; j < 2; j++) {
      for (int mask = 0; mask < (1 << nn[j]); mask++) {
        long long now = 1;
        for (int i = 0; i < nn[j]; i++) if (mask & (1<<i))
          now = mul(now, a[off[j]+i], k);
        if (now <= k)
          val[j].push_back(now);
      }
      sort(val[j].begin(), val[j].end());
    }
    int ans = 0, j = 0;
    for (int i = (int)val[0].size()-1; i >= 0;  i--) {
      while (j < val[1].size() && mul(val[0][i], val[1][j], k) <= k) j++;
      ans += j;
    }
    ans--;
    printf("%d\n", ans);
  }
  return 0;
}