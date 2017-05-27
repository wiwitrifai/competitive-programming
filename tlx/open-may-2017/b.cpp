#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

long long a[N][6];
long long val[N][1<<5];
set< pair< long long, int > > st[1 << 5];
int n, k, kk;
long long get() {
  long long ans = 0;
  for (int mask = 0; mask < kk; mask++) {
    int b = mask ^ (kk-1);
    ans = max(-st[mask].begin()->first-st[b].begin()->first, ans);
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &k);
  kk = 1 << k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++)
      scanf("%lld", a[i]+j);
    for (int mask = 0; mask < kk; mask++) {
      long long cur = 0;
      for (int j = 0; j < k; j++)
        if (mask & (1<<j))
          cur += a[i][j];
        else
          cur -= a[i][j];
      val[i][mask] = cur;
      st[mask].insert(make_pair(cur, i));
    }
  }
  printf("%lld\n", get());
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    x--;
    for (int j = 0; j < k; j++)
      scanf("%lld", a[x]+j);
    for (int mask = 0; mask < kk; mask++) {
      long long cur = 0;
      for (int j = 0; j < k; j++)
        if (mask & (1<<j))
          cur += a[x][j];
        else
          cur -= a[x][j];
      st[mask].erase(make_pair(val[x][mask], x));
      val[x][mask] = cur;
      st[mask].insert(make_pair(cur, x));
    }
    printf("%lld\n", get());
  }
  return 0;
}