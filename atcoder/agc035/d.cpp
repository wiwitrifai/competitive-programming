#include <bits/stdc++.h>

using namespace std;

const int N = 18;
const long long inf = 2e18;

map<pair<int, int>, long long> dp[N][N];
int a[N];

long long rec(int l, int r, pair<int, int> c) {
  if (l+1 == r)
    return 0;
  auto it = dp[l][r].find(c);
  if (it != dp[l][r].end())
    return it->second;
  int cl = c.first, cr = c.second, sum = cl + cr;
  long long ret = inf;
  for (int i = l+1; i < r; ++i) {
    ret = min(ret, rec(l, i, make_pair(cl, sum)) + rec(i, r, make_pair(sum, cr)) + 1LL * a[i] * sum);
  }
  return dp[l][r][c] = ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  printf("%lld\n", rec(0, n-1, make_pair(1, 1)) + a[0] + a[n-1]);
  return 0;
}
