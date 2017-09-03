#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

long long dp[N][N];
int a[N][N], n, m, k;
long long tmp[N][N];
bool telp[N];
deque<long long> dq[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", a[i]+ j);
      }
    }
    memset(telp, 0, sizeof telp);
    for (int i = 0; i < m; i++) {
      int b;
      scanf("%d", &b);
      b--;
      telp[b] = 1;
    }
    for (int i = 0; i < n; i++)
      dq[i].clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + a[i][j];
        if (!dq[j].empty())
          dp[i][j] = max(dp[i][j], a[i][j] + dq[j].front());
      }
      if (i >= k  && telp[i-k]) {
        for (int j = 0; j < n; j++) {
          if (!dq[j].empty() && tmp[i-k][j] == dq[j].front())
            dq[j].pop_front();
        }
      }
      if (telp[i]) {
        long long cur = -1e18;
        for (int j = 0; j < n; j++) {
          tmp[i][j] = cur;
          cur = max(cur, dp[i][j]);
        }
        cur = -1e18;
        for (int j = n-1; j >= 0; j--) {
          tmp[i][j] = max(cur, tmp[i][j]);
          cur = max(cur, dp[i][j]);
        }
        for (int j = 0; j < n; j++) {
          while (!dq[j].empty() && dq[j].back() < tmp[i][j])
            dq[j].pop_back();
          dq[j].push_back(tmp[i][j]);
        }
      }
    }
    long long ans = -1e18;
    for (int i = 0; i < n; i++)
      ans = max(ans, dp[n-1][i]);
    printf("%lld\n", ans);
  }
  return 0;
}