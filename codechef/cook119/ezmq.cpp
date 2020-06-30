#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<long long> a(n);
const int N = 5050;
const long long inf = 1e18;

long long dp[N][N], tmp[N];

void solve(int l, int r) {
  if (l >= r) return;
  if (r-l < 2) {
    dp[l][0] = 0;
    dp[l][1] = a[l];
    return;
  }
  int mid = l;
  for (int i = l; i < r; ++i) {
    if (a[i] > a[mid]) {
      mid = i;
    }
  }
  solve(l, mid);
  solve(mid+1, r);
  fill(tmp+1, tmp+r-l+1, inf);
  tmp[0] = 0;
  int sl = mid-l, sr = r-mid-1;
  int x = mid+1;
  for (int i = 0; i <= sl; ++i) {
    for (int j = 0; j <= sr; ++j) {
      long long res = dp[l][i] + dp[x][j];
      res = min(res, inf);
      res += i * j * a[mid];
      tmp[i+j] = min(tmp[i+j], res);
      res = min(res, inf);
      res += (i+j+1) * a[mid];
      tmp[i+j+1] = min(tmp[i+j+1], res);
    }
  }
  for (int i = 0; i <= r-l; ++i)
    dp[l][i] = tmp[i];
}

void solve() {
  scanf("%d %d", &n, &k);
  a.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  solve(0, n);
  printf("%lld\n", dp[0][k]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
