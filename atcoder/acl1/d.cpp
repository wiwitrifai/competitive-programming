#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  vector<vector<int>> to_lef(32 - __builtin_clz(n)), to_rig(32 - __builtin_clz(n));
  vector<vector<long long>> sum_lef(32 - __builtin_clz(n)), sum_rig(32 - __builtin_clz(n));
  for (int i = 0, j = -1; i < n; ++i) {
    while (j + 1 < n && x[i] - x[j + 1] >= k) ++j;
    to_lef[0].push_back(j);
    sum_lef[0].push_back(i);
  }
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && x[j] - x[i] < k) ++j;
    to_rig[0].push_back(j);
    sum_rig[0].push_back(i-1);
  }
  for (int i = 0; i + 1 < (int)to_lef.size(); ++i) {
    to_lef[i+1].resize(n);
    sum_lef[i+1].resize(n);
    for (int j = 0; j < n; ++j) {
      int now = to_lef[i][j];
      long long sum = sum_lef[i][j];
      if (now != -1) {
        sum += sum_lef[i][now];
        now = to_lef[i][now];
      }
      to_lef[i+1][j] = now;
      sum_lef[i+1][j] = sum;
    }
  }
  for (int i = 0; i + 1 < (int)to_rig.size(); ++i) {
    to_rig[i+1].resize(n);
    sum_rig[i+1].resize(n);
    for (int j = 0; j < n; ++j) {
      int now = to_rig[i][j];
      long long sum = sum_rig[i][j];
      if (now < n) {
        sum += sum_rig[i][now];
        now = to_rig[i][now];
      }
      to_rig[i+1][j] = now;
      sum_rig[i+1][j] = sum;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    long long ans = 0;
    int now = r;
    for (int i = (int) to_lef.size()-1; i >= 0; --i) {
      if (to_lef[i][now] >= l) {
        ans += sum_lef[i][now];
        now = to_lef[i][now];
      }
    }
    ans += now;
    now = l;
    for (int i = (int) to_rig.size()-1; i >= 0; --i) {
      if (to_rig[i][now] <= r) {
        ans -= sum_rig[i][now];
        now = to_rig[i][now];
      }
    }
    ans -= now - 1;
    printf("%lld\n", ans);
  }
  return 0;
}
