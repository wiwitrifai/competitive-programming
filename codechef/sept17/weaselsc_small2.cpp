#include <bits/stdc++.h>

using namespace std;

const int N = 1505, inf = 1e9 + 7;

int n, k;
int h[N];
long long dp[N][N][55];
long long tmp[55];
vector<int> vh;

long long solve() {
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++)
    dp[i][vh.size() - 1][0] = 0;
  long long ans = -1;
  for (int i = 0; i < n; i++) {
    memset(tmp, -1, sizeof tmp);
    for (int j = vh.size() - 1; j >= 0; j--) {
      if (h[i] >= j) {
        for (int z = 0; z <= k; z++) {
          dp[i+1][j][z] = max(z ? tmp[z-1] : -1, dp[i][j][z]);
          if (dp[i+1][j][z] >= 0) {
            dp[i+1][j][z] += vh[j];
            ans = max(ans, dp[i+1][j][z]);
          }
        }
      }
      for (int z = 0; z <= k; z++)
        tmp[z] = max(tmp[z], dp[i][j][z]);
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    k++;
    vh.clear();
    vh.push_back(inf);
    for (int i = 0; i < n; i++) {
      scanf("%d", h+i);
      vh.push_back(h[i]);
    }
    sort(vh.begin(), vh.end());
    vh.erase(unique(vh.begin(), vh.end()), vh.end());
    for (int i = 0; i < n; i++)
      h[i] = lower_bound(vh.begin(), vh.end(), h[i]) - vh.begin();
    long long ans = solve();
    reverse(h, h+n);
    ans = max(ans, solve());
    printf("%lld\n", ans);
  }
  return 0;
}