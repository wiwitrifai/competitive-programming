#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];
int lef[N], rig[N];
int pre[N];
int lis[N];

void solve() {
  int n;
  scanf("%d", &n);
  int len = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    int p = lower_bound(lis, lis+len, a[i]) - lis;
    lef[i] = p;
    pre[i] = p ? lis[p-1] : -1;
    lis[p] = a[i];
    len += p == len;
  }
  int maxi = len;
  len = 0;
  for (int i = n-1; i >= 0; --i) {
    int p = lower_bound(lis, lis+len, -a[i]) - lis;
    rig[i] = p;
    lis[p] = -a[i];
    len += p == len;
  }
  int ans = maxi;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= maxi)
      continue;
    if (lef[i] + rig[i] + 1 != maxi) continue;
    if (pre[i] < maxi) {
      ans = max(ans, a[i]);
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
