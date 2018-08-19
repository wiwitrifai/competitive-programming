#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int dp[2][N * N];
int a[N];
int m, k;

int upper;

void upd(int & var, int val) {
  if (var < val)
    var = val;
}

void solve(int tc) {
  printf("Case #%d: ", tc);
  scanf("%d %d", &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%d", a+i);
  }
  upper = 0;
  for (int i = 0; i < m; ++i)
    upper = max(upper, a[i]);
  int batas = (m * 2 - 1) * k;
  int ans = 0;
  int mm = m * 2 - 1;
  while (upper <= batas) {
    int c = 0, b = 1;
    for (int i = 0; i <= upper; ++i)
      dp[c][i] = 0;
    for (int i = 0; i <= upper; ++i)
      dp[b][i] = 0;
    dp[c][0] = 0;
    for (int i = 0; i < mm; ++i) {
      swap(b, c);
      for (int j = 0; j <= upper; ++j) {
        dp[c][j] = 0;
      }
      if ((i & 1) == 0) {
        int now = a[i / 2];
        if (now < 0) {
          upd(dp[c][0], 0);
          for (int j = 0; j <= upper; ++j) {
            if (dp[b][j] < 0) continue;
            upd(dp[c][0], dp[b][j] + now);
          }
        }
        else {
          for (int j = 0; j + now <= upper; ++j) {
            if (dp[b][j] < 0) continue;
            upd(dp[c][j+now], dp[b][j] + now);
          }
        }
        for (int j = 0; j <= upper; ++j)
          upd(ans, dp[c][j] - upper);
      }
      else {
        upd(dp[c][0], 0);
        for (int j = 0; j <= upper; ++j) {
          if (dp[b][j] < 0) continue;
          int cost = min(upper-j, k);
          upd(dp[c][j+cost], dp[b][j] + cost);
          upd(dp[c][0], dp[b][j] - 1);
        }
        if (a[(i+1)/2] <= 0) {
          for (int j = 0; j <= upper; ++j)
            upd(ans, dp[c][j] - upper);
        }
      }
    }
    ++upper;
  }
  printf("%d\n", ans);
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
    fflush(stdout);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}