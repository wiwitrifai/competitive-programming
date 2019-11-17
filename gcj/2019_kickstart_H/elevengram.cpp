#include <bits/stdc++.h>

using namespace std;

int a[12];
void read_input() {
  for (int i = 1; i <= 9; ++i) {
    scanf("%d", a+i);
  }
}

int dp[11][11 * 11][11];

void upd(int & var, int val) {
  if (var < val)
    var = val;
}

void solve() {
  long long tot = 0;
  for (int i = 1; i <= 9; ++i) {
    tot = (tot + 1LL * i * a[i]);
  }
  memset(dp, -1, sizeof dp);
  dp[0][0][0] = 0;
  int maxi = 10 * 10;
  for (int d = 1; d <= 9; ++d) {
    for (int k = 0; k < maxi; ++k) {
      for (int r = 0; r < 11; ++r) {
        if (dp[d-1][k][r] == -1) continue;
        int cur = dp[d-1][k][r];
        for (int j = 0; j <= min(10, a[d]); ++j) {
          upd(dp[d][k + j][(r + j * d) % 11], cur + (a[d] - j) / 11);
        }
      }
    }
  }
  int r = 6LL * tot % 11;
  long long target = 0;
  for (int i = 1; i <= 9; ++i)
    target += a[i];
  target /= 2;
  for (int k = 0; k < maxi; ++k) {
    if (dp[9][k][r] == -1) continue;
    if (k > target) continue;
    long long up = k + 11LL * dp[9][k][r];
    if (up < target) continue;
    if ((target - k) % 11) continue;
    puts("YES");
    return;
  }
  puts("NO");
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
