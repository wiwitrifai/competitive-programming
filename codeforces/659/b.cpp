#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int dp[N][N][2][2];

int solve(int one, int zero, int me, int he) {
  if (one == 0 && zero == 0) {
    assert(me != he);
    return me == 1;
  }
  int & ret = dp[one][zero][me][he];
  if (ret != -1)
    return ret;
  ret = 0;
  if (one > 0 && solve(one-1, zero, he, me^1) == 0)
    return ret = 1;
  if (zero > 0 && solve(one, zero-1, he, me) == 0)
    return ret = 1;
  return ret;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  int all = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]), all ^= a[i];
  if (all == 0) {
    puts("DRAW");
    return;
  }
  int mask = 0;
  for (int i = 0; i <= 30; ++i) {
    if ((all >> i) & 1)
      mask = 1 << i;
  }
  int one = 0;
  for (int x : a)
    if (mask & x)
      ++one;
  int k = (one - 1) / 2;
  if (k & 1) {
    int zero = n - one;
    puts((zero & 1) ? "WIN" : "LOSE");
  } else {
    puts("WIN");
  }
}

int main() {
  // memset(dp, -1, sizeof dp);
  // for (int one = 1; one <= 20; one += 2) {
  //   for (int zero = 0; zero <= 20; ++zero) {
  //     cerr << one << " " << zero << " " << solve(one, zero, 0, 0) << endl;
  //   }
  // }

  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
