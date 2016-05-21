#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
bool rotate;
int n, m;
vector< vector< int > > mat;
int cnt[N];

int main() {
  memset(cnt, 0, sizeof cnt);
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    scanf("%d%d", &n, &m);
    mat.assign(n+2, vector<int>(m+2));
    // ans.assign(n+2, vector<int>(m+2));
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<m; j++) {
        scanf("%d", &mat[i][j]);
      }
    }
    int ans = 0;
    if(n < m) {
      for(int i = 0; i<n; i++) {
        int bef = 0;
        for(int j = 0; j<m; j++) {
          cnt[mat[i][j]]++;
          bef = max(cnt[mat[i][j]], bef);
        }
        for(int j = 0; j<m; j++) {
          int now = bef;
          for(int k = 0; k<n; k++)
            if(k != i) {
              int x = mat[k][j];
              cnt[x]++;
              now = max(now, cnt[x]);
            }
          for(int k = 0; k<n; k++)
            cnt[mat[k][j]] -= (k!=i);
          ans = max(ans, now);
        }
        for(int j = 0; j<m; j++) {
          cnt[mat[i][j]]--;
        }
      }
    }
    else {
      for(int j = 0; j<m; j++) {
        int bef = 0;
        for(int i = 0; i<n; i++) {
          cnt[mat[i][j]]++;
          bef = max(cnt[mat[i][j]], bef);
        }
        for(int i = 0; i<n; i++) {
          int now = bef;
          for(int k = 0; k<m; k++)
            if(k != j) {
              int x = mat[i][k];
              cnt[x]++;
              now = max(now, cnt[x]);
            }
          for(int k = 0; k<m; k++)
            cnt[mat[i][k]] -= (k!=j);
          ans = max(ans, now);
        }
        for(int i = 0; i<n; i++) {
          cnt[mat[i][j]]--;
        }
      }
    }
    // for(int i = 0; i<n; i++) {
    //   for(int j = 0; j<m; j++)
    //     printf("%d ", ans[i][j]);
    //   printf("\n");
    // }
    printf("%d\n", ans);
  }
  
  return 0;
}