#include <bits/stdc++.h>

using namespace std;

const int N = 505, inf = 1e9 + 7;

int dp[N][N];
int a[N], b[N];
int cost[N];

void process(int x, int y, int k) {
  if (x >= k && y >= k) {
    for (int i = 0; i < k; ++i)
      cost[i] = 0;
    return;
  }
  for (int i = 0; i < k; ++i)
    cost[i] = inf;
  if (y < k) {
    for (int i = 0; i <= y; ++i) {
      int now = min(x, k-i);
      for (int j = 0; j < k; ++j)  {
        cost[i] = min(cost[i], (j+1) * k - (i+now));
        now = min(x, now + k);
      }
    }
  }
  else {
    for (int i = 0; i < k; ++i) {
      int now = i;
      for (int j = 0; j < k && now <= y; ++j, now += y) {
        int cnt = (now + k - 1) / k;
        int sisa = max(cnt * k - now - x, 0);
        cost[i] = min(cost[i], sisa);
      }
    }
  }
}


int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long suma = 0, sumb = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
    suma += a[i];
    sumb += b[i];
  }
  int ra = suma % k, rb = sumb % k;
  long long ans = suma/k + sumb/k;
  if (ra + rb < k) {
    printf("%lld\n", ans);
    return 0;
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= k; ++j)
      dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    process(a[i], b[i], k);
    for (int j = 0; j < k; ++j) {
      if (dp[i][j] >= inf) continue;
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      for (int z = 0, w = j; z < k; ++z, w = w+1 == k ? 0 : w+1) {
        if (cost[z]) continue;
        dp[i+1][w] = min(dp[i+1][w], dp[i][j] + cost[z]);
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    int j = k - i;
    if (i > rb || j > ra) continue;
    if (dp[n][i] == 0) {
      ++ans;
      break;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
