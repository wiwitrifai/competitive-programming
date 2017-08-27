#include <bits/stdc++.h>

using namespace std;

const int N = 602, inf = 1e8;

char s[N];
int dp[N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%s", s);
    int n = strlen(s);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
      dp[i] = inf;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        bool ok = 0;
        int len = j-i+1;
        for (int k = 0; k + len <= i; k++) {
          ok = 1;
          for (int z = 0; z < len; z++)
            if (s[k+z] != s[i+z]) {
              ok = 0;
              break;
            }
          if (ok) break;
        }
        if (ok) {
          int cur = dp[i] + 1;
          for (int k = i; k+len <= n; k ++) {
            cur++;
            ok = 1;
            for (int z = 0; z < len; z++)
              if (s[k+z] != s[i+z]) {
                ok = 0;
                break;
              }
            if (ok) {
              dp[k+len] = min(dp[k+len], cur);
              k += len-1;
            }
          }
        }
      }
      dp[i+1] = min(dp[i+1], dp[i]+1);
    }
    printf("Case #%d: %d\n", tc, dp[n]);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}