#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100, M = 447, mod = 1e9 + 7;

int cnt[N], a[N];
long long incc[N], decc[N];

long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}
long long ans[N];
pair<int, int> que[N], event[N];
int bef[N];

int main() {
  for (int i = 0; i < N; i++) {
    incc[i] = decc[i] = 1;
  }
  for (int i = 1; i < N; i++) {
    long long val = powmod(i, i);
    long long inv = powmod(i, mod-1-i);
    incc[i] = (incc[i] * val) % mod;
    if (i+1 < N)
      incc[i+1] = (incc[i+1] * inv) % mod;
    decc[i] = (decc[i] * val) % mod;
    if (i-1 >= 0)
      decc[i-1] = (decc[i-1] * inv) % mod; 
  }
  int n, q;
  scanf("%d %d", &n, &q);
  int m = 0;
  memset(a, 0, sizeof a);
  // if (n < 2000) {
  //   for (int i = 0; i < q; i++) {
  //     int ty, x, y;
  //     scanf("%d %d", &ty, &x);
  //     if (ty == 1) {
  //       scanf("%d", &y);
  //       x--;
  //       a[x] = y;
  //     }
  //     else {
  //       for (int j = 0; j <= n+1; j++)
  //         cnt[j] = 1;
  //       for (int j = 0; j < x; j++)
  //         cnt[a[j]]++;
  //       long long ans = 1;
  //       for (int j = 0; j <= n+1; j++)
  //         if (cnt[j] > 1)
  //           ans = (ans * powmod(cnt[j], cnt[j])) % mod;
  //       printf("%lld\n", ans);
  //     }
  //   }
  //   return 0;
  // }
  for (int i = 0; i < q; i++) {
    int ty, x, y;
    scanf("%d %d", &ty, &x);
    if (ty == 1) {
      scanf("%d", &y);
      x--;
      que[i] = {x, y};
      bef[i] = a[x];
      a[x] = y;
    }
    else {
      que[i] = {-1, x};
      event[m++] = {i, x};
      bef[i] = -1;
    }
  }
  sort(event, event+m, [](pair<int, int> aa, pair<int, int> b) {
    int ga = aa.first / M, gb = b.first / M;
    if (ga != gb)
      return ga < gb;
    return aa.second < b.second;
  });
  for (int i = 0; i <= n+3; i++) {
    cnt[i] = 1;
    a[i] = 0;
  }
  int r = 0, k = -1;
  long long now = 1;
  for (int i = 0; i < m; i++) {
    int id = event[i].first, p = event[i].second;
    while (r < p) {
      int res = ++cnt[a[r]];
      now = (now * incc[res]) % mod;
      r++;
    }
    while (r > p) {
      r--;
      int res = --cnt[a[r]];
      now = (now * decc[res]) % mod;
    }
    while (k < id) {
      k++;
      if (que[k].first < 0)
        continue;
      if (que[k].first >= r) {
        a[que[k].first] = que[k].second;
        continue;
      }
      int x = que[k].first;
      int res = --cnt[a[x]];
      now = (now * decc[res]) % mod;
      a[x] = que[k].second;
      res = ++cnt[a[x]];
      now = (now * incc[res]) % mod;
    }
    while (k > id) {
      if (que[k].first < 0) {
        k--;
        continue;
      }
      if (que[k].first >= r) {
        a[que[k].first] = bef[k];
        k--;
        continue;
      }
      int x = que[k].first;
      int res = --cnt[a[x]];
      now = (now * decc[res]) % mod;
      a[x] = bef[k];
      res = ++cnt[a[x]];
      now = (now * incc[res]) % mod;
      k--;
    }
    now %= mod;
    if (now < 0)
      now += mod;
    ans[k] = now;
  }
  for (int i = 0; i < n; i++) if (que[i].first < 0)
    printf("%lld\n", ans[i]);
  return 0;
}