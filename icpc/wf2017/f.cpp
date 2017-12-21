#include <bits/stdc++.h>

using namespace std;

const int N = 300;
const long long inf = 1e18;

long long dp[N][N], p[N];

long long add[N][N];

long long upd(long long& at, long long val) {
  at = min(at, val);
}

int main() {
  int d, k;
  scanf("%d %d", &d, &k);
  for (int i = 0; i < d; i++) {
    int at, v;
    scanf("%d %d", &at, &v);
    p[at] = v;
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      add[i][j] = add[i][j-1] + 1LL * (j - i) * (j - i) * p[j];
    }
    for (int j = i - 1; j >= 0; j--) {
      add[i][j] = add[i][j+1] + 1LL * (i - j) * (i - j) * p[j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = inf;
    }
    dp[i][1] = add[i][0];
  }
  for (int i = 0; i < N; i++) {
    for (int bef = 0; bef < i; bef++) {
      int mid = (i + bef) / 2;
      for (int j = 2; j <= k; j++) {
        upd(dp[i][j], dp[bef][j-1] + add[bef][mid] + add[i][mid+1]);
      }
    }
  }
  long long ans = inf;
  for (int i = 0; i < N; i++) {
    upd(ans, dp[i][k] + add[i][N - 1]);
  }
  cout << ans << endl;
  return 0;
}