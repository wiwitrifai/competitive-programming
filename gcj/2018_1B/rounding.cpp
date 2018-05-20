#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e4 + 4, inf = 1e8;

int c[N];
int dp[M][202];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n, k;
    scanf("%d %d", &n, &k);
    fill(c, c+n, 0);
    int sisa = n;
    for (int i = 0; i < k; ++i)
      scanf("%d", c+i), sisa -= c[i];
    vector<int> v;
    for (int i = 0; i <= 100; ++i) {
      int now = i * 10 + 5;
      int mi = (n * now + 999) / 1000;
      v.push_back(mi);
    }
    sort(v.begin(), v.end());
    sort(c, c+n);
    int ans = 0, last = 0, cnt = 0;
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      if (last == c[i] && cnt >= 200) {
        ans += upper_bound(v.begin(), v.end(), c[i]) - v.begin();
      }
      else {
        s.push_back(c[i]);
        if (last != c[i])
          last = c[i], cnt = 0;
        ++cnt;
      }
    }
    dp[0][0] = 0;
    for (int j = 1; j <= 200; ++j)
      dp[0][j] = inf;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= 200; ++j) {
        dp[i+1][j] = dp[i][j];
      }
      int id = upper_bound(v.begin(), v.end(), s[i]) - v.begin();
      for (int j = 0; j+id <= 200; ++j)
        dp[i+1][j+id] = min(dp[i+1][j+id], dp[i][j]);
      for (int j = 0; j <= 200; ++j) {
        int now = dp[i][j];
        if (now > sisa) continue;
        for (int k = id+1; k <= v.size(); ++k) {
          int cur = now + v[k-1] - s[i];
          if (cur > sisa) continue;
          if (j + k > 200) break;
          dp[i+1][j+k] = min(dp[i+1][j+k], cur);
        }
      }
    }
    int ma = 0;
    for (int j = 0; j <= 200; ++j) {
      if (dp[(int)s.size()][j] <= sisa)
        ma = max(ma, j);
    }
    ans += ma;
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}