#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, K = 101;
const long long inf = 1e15;

long long up[N], down[N];

int p[N];
vector<int> zero;

long long dp[N], bef[N];

void dnc(int k, int l, int r, int from, int til) {
  if (r <= l)
    return;
  int mid = (l + r) >> 1;
  int sel = mid;
  long long best = bef[mid];
  for (int i = from; i < til && i <= mid; ++i) {
    long long cur = (i < 0 ? 0 : bef[i]) + up[zero[mid]] - (i >= 0 ? up[zero[i]] : 0)
      + ((i+1 < (int)zero.size() ? down[zero[i+1]] : 0) - (mid + 1 < (int)zero.size() ? down[zero[mid+1]] : 0))
      + 1LL * (i + 1) * (mid - i);
    if (best < cur) {
      best = cur;
      sel = i;
    }
  }
  dp[mid] = best;
  dnc(k, l, mid, from, sel+1);
  dnc(k, mid+1, r, sel, til);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    if (p[i] == 0)
      zero.push_back(i);
  }
  long long ans = 0;
  int cnt[105];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    if (p[i] != 0) {
      for (int j = p[i]+1; j <= k; ++j)
        ans += cnt[j];
      ++cnt[p[i]];
    }
  }
  fill(dp, dp+(int)zero.size(), -inf);
  for (int i = k; i >= 1; --i) {
    int cur = 0;
    long long sum = 0;
    for (int j = 0; j < n; ++j) {
      if (p[j] == 0)
        sum += cur;
      up[j] = sum;
      if (p[j] != 0 && p[j] > i)
        ++cur;
    }
    cur = 0;
    sum = 0;
    for (int j = n-1; j >= 0; --j) {
      if (p[j] == 0)
        sum += cur;
      down[j] = sum;
      if (p[j] != 0 && p[j] < i)
        ++cur;
    }
    for (int j = 0; j < (int)zero.size(); ++j)
      bef[j] = dp[j];
    dnc(i, 0, zero.size(), -1, (int)zero.size());
  }
  printf("%lld\n", ans + dp[(int)zero.size()-1]);
  return 0;
}
