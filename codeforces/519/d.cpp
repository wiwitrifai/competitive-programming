#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int nxt[N], tmp[N];
int dp[N];

int calc(int x) {
  if (x == 0) return 0;
  if (dp[x] > 0)
    return dp[x];
  return dp[x] = 1 + calc(nxt[x]);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int pre = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (pre != 0) {
      nxt[pre] = a;
    }
    pre = a;
  }
  for (int i = 1; i < m; ++i) {
    int pre = 0;
    memset(tmp, 0, sizeof tmp);
    for (int j = 0; j < n; ++j) {
      int a;
      scanf("%d", &a);
      if (pre != 0) {
        tmp[pre] = a;
      }
      pre = a;
    }
    for (int j = 1; j <= n; ++j) {
      if (nxt[j] != tmp[j])
        nxt[j] = 0;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += calc(i);
  printf("%lld\n", ans);
  return 0;
}