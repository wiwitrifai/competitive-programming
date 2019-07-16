#include <bits/stdc++.h>

using namespace std;

long long n;

int sum[30];
int a[30];
long long ans = 0;
int cal[30];

void dfs(int pos, long long now) {
  if (now == 0) {
    for (int len = 1; len < pos; ++len) {
      bool ok = 1;
      for (int i = 0; i < pos-len; ++i)
        a[pos-1-i] = sum[pos-1-i];
      int cur = pos-len;
      while (cur < pos) {
        for (int i = 0; i < cur; ++i)
          a[i] = a[pos-1-i];
        for (int i = 0; i < min(cur, len); ++i) {
          int id = len-1-i;
          int v = sum[i] - a[i];
          a[id] = sum[id] - v;
        }
        cur += pos-len;
      }
      ok &= a[0] > 0 && sum[0] - a[0] > 0;
      for (int i = 0, j = pos-1; i <= j; ++i, --j) {
        if (a[i] > 9 || a[i] < 0) ok = 0;
        if (a[i] != a[j]) ok = 0;
      }
      for (int i = len; i < pos; ++i)
        if (sum[i] - a[i] != 0)
          ok = 0;
      for (int i = 0, j = len-1; i <= j; ++i, --j) {
        int vi = sum[i]-a[i], vj = sum[j]-a[j];
        if (vi != vj) ok = 0;
        if (vi > 9 || vi < 0) ok = 0;
      }
      if (ok)
        ans += 2;
    }
    if (sum[0] == sum[pos-1] && sum[0] > 1) {
      int l = 1, r = 9;
      r = min(r, sum[0]-1);
      l = max(l, sum[0]-r);
      long long mul = max(r-l+1, 0);
      for (int i = 1, j = pos-2; i <= j; ++i, --j) {
        if (sum[i] != sum[j]) {
          mul = 0;
          break;
        }
        mul *= cal[sum[i]];
      }
      ans += mul;
    }
  }
  else {
    sum[pos] = now % 10;
    now /= 10;
    dfs(pos+1, now);
    if (sum[pos] != 9 && now > 0) {
      sum[pos] += 10;
      --now;
      dfs(pos+1, now);
    }
  }
}

int main() {
  scanf("%lld", &n);
  cal[0] = 1;
  for (int i = 1; i <= 18; ++i) {
    int l = 0, r = 9;
    r = min(r, i);
    l = max(l, i-r);
    cal[i] = r-l+1;
  }
  dfs(0, n);
  printf("%lld\n", ans);
  return 0;
}