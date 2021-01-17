#include <bits/stdc++.h>

using namespace std;

const int N = 303, mod = 998244353;

int dp[N][N];

void upd(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  vector<int> other;
  int last = 0;
  vector<int> val(n, 0);
  for (int i = 0; i < n; ++i) {
    if (a[i] < i) {
      if (a[i] != last) {
        puts("0");
        return;
      }
      last = i;
      val[i] = -1;
      for (int j = a[i]+1; j < i; ++j)
        val[j] = 1;
    }
    else {
      if (a[i] == i) {
        puts("0");
        return;
      }
      other.push_back(a[i]);
    }
  }
  for (int i = 0; i+1 < (int)other.size(); ++i) {
    if (other[i+1] < other[i]) {
      puts("0");
      return;
    }
  }
  dp[1][0] = 1;
  for(int i = 1; i < n-1; ++i) {
    for (int j = 0; j < i; ++j) {
      int from = 0, til = i;
      int cur = dp[i][j];
      if (val[i] == 1)
        from = j+1;
      else
        til = j;
      for (int k = from; k <= til; ++k)
        upd(dp[i+1][k], cur);
    }
  }
  int ans = 0;
  for (int i = 0; i < n-1; ++i)
    upd(ans, dp[n-1][i]);
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
