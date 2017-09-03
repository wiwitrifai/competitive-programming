#include <bits/stdc++.h>

using namespace std;

const int N = 605;

const long long inf = 1e15;

long long dp[2][N]; 
string s; 

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    assert(n > 0 && m >= 5); 
    n *= 2;
    memset(dp, 0, sizeof dp);
    for (int l = 0; l <= n; l++) {
      int c = l & 1, d = c ^ 1;
      getline(cin, s);
      while (s.size() == 0)
        getline(cin, s);
      long long now = -inf;
      for (int i = 0; i < m; i++) {
        if (s[i] == '#')
          now = -inf;
        else {
          now = max(now, dp[c][i]);
          if (s[i] == '.' && now >= 0)
            now++;
        }
        dp[d][i] = now;
      }
      now = -inf;
      for (int i = m-1; i >= 0; i--) {
        if (s[i] == '#')
          now = -inf;
        else {
          now = max(now, dp[c][i]);
          if (s[i] == '.' && now >= 0)
            now++;
        }
        dp[d][i] = max(now, dp[d][i]);
      }
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      // cerr << dp[0][i] << " " << dp[1][i] << endl;
      ans = max(ans, dp[1][i]);
    }
    printf("%lld\n", ans);
  }

  return 0;
}