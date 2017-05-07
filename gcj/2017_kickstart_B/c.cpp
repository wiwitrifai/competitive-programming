#include <bits/stdc++.h>

using namespace std;

const int N = 104;

bool tri[N][N][N];
int dp[N][N][N];
char s[N][N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
      scanf("%s", s[i]);
    memset(tri, 0, sizeof tri);
    memset(dp, 0, sizeof dp);
    int ma = 0;
    for (int i = n-1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '.') continue;
        tri[i][j][0] = 1;
        dp[i][j][0] = 1;
        for (int z = 1; z < N; z++) {
          if (j-1 < 0 || !tri[i+1][j-1][z-1]) break;
          if (!tri[i+1][j][z-1]) break;
          if (j+1 >= m || !tri[i+1][j+1][z-1]) break;
          tri[i][j][z] = 1;
          dp[i][j][0] = (z + 1) * (z + 1);
          ma = max(ma, z);
        }
      }
    }
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '.') continue;
        for (int z = 0; z < k; z++) {
          if (dp[i][j][z] == 0) continue; 
          int cur = dp[i][j][z];
          for (int w = 0; w <= ma; w++) {
            if (i-w-1 < 0) break;
            for (int y = max(j-w, 0); y <= min(m-1, j+w); y++) {
              if (!tri[i-w-1][y][w]) continue;
              int & now = dp[i-w-1][y][z+1];
              now = max(now, (w + 1) * (w+1) + cur);
            }
          }
        }
        ans = max(ans, dp[i][j][k-1]);
      }
    }
    printf("Case #%d: %d\n", tc, ans);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}