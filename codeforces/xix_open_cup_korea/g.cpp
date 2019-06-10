#include <bits/stdc++.h>

using namespace std;

const int N = 250005;

const long long inf = 1e17;

int w[N];

long long dp[2][10][10][3];

int n, k;
void reset(int c) {
  for (int i = 0; i <= k; ++i)
    for (int j = 0; j <= k; ++j)
      dp[c][i][j][0] = dp[c][i][j][1] = dp[c][i][j][2] = inf;
}

void upd(long long & var, long long val) {
  if (var > val)
    var = val;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", w+i);
  reset(0);
  reset(1);
  int c = 0, b = 1;
  dp[c][0][0][1] = 0;
  for (int i = 0; i < n; ++i) {
    int now = w[i];
    swap(c, b);
    reset(c);
    for (int ambil = 0; ambil <= k; ++ambil) {
      for (int taruh = 0; taruh <= k; ++taruh) {
        upd(dp[c][ambil][taruh][2], dp[b][ambil][taruh][1]);
        upd(dp[c][ambil][taruh][1], dp[b][ambil][taruh][0]);

        upd(dp[c][ambil][taruh][0], dp[b][ambil][taruh][0] + now);
        upd(dp[c][ambil][taruh][0], dp[b][ambil][taruh][1] + now);
        upd(dp[c][ambil][taruh][0], dp[b][ambil][taruh][2] + now);
        if (ambil < k) {
          upd(dp[c][ambil+1][taruh][1], dp[b][ambil][taruh][0] + now);
          upd(dp[c][ambil+1][taruh][2], dp[b][ambil][taruh][1] + now);
        }
        if (taruh < k) {
          upd(dp[c][ambil][taruh+1][0], dp[b][ambil][taruh][0]);
          upd(dp[c][ambil][taruh+1][0], dp[b][ambil][taruh][1]);
          upd(dp[c][ambil][taruh+1][0], dp[b][ambil][taruh][2]);
        }
      }
    }
  }
  long long ans = inf;
  for (int i = 0; i <= k; ++i)
    upd(ans, min(dp[c][i][i][0], dp[c][i][i][1]));
  printf("%lld\n", ans);
  return 0;
}
