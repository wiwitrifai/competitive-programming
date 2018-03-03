#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, K = 111;
const long double inf = 1e19 + 19;

long double sum2[N], sum[N];

long double calc(int l, int r) {
  long double c = sum2[r] - sum2[l], b = sum[r] - sum[l];
  return c - b * b / (r-l);
}

long double dp[N], pre[N];

void solve(int l, int r, int lo, int hi) {
  if (l > r) return;
  if (lo == hi) {
    dp[l] = pre[lo] + calc(lo, l);
    for (int i = l+1; i <= r; ++i)
      dp[i] = pre[lo] + calc(lo, i);
    return;
  }
  int mid = (l + r) >> 1;
  int best = min(lo, mid-1);
  dp[mid] = pre[lo] + calc(lo, mid);
  for (int i = lo; i <= min(hi, mid-1); ++i) {
    long double cur = pre[i] + calc(i, mid);
    if (dp[mid] > cur) {
      dp[mid] = cur;
      best = i;
    }
  }
  solve(l, mid-1, lo, best);
  solve(mid+1, r, best, hi);
}

int x[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", x+i);
  }
  sort(x, x+n);
  for (int i = 0; i < n; ++i) {
    sum[i+1] = sum[i] + x[i];
    sum2[i+1] = sum2[i] + 1LL * x[i] * x[i];
  }
  for (int i = 0; i <= n; ++i)
    dp[i] = inf;
  dp[0] = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j <= n; ++j)
      pre[j] = dp[j];
    pre[0] = 0;
    solve(1, n, 0, n-1);
  }
  cout << setprecision(12) << fixed;
  cout << dp[n] << endl;
  return 0;
}