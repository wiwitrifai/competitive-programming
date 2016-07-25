#include <bits/stdc++.h>

using namespace std;
const int N = 102;
const int inf = 1e8;
int s[N][N];
int n, m, k[2], xa[2], ya[2];
int d[2][N][N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d%d", &n, &m, k, k+1);
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++)
        scanf("%d", s[i]+j);
    memset(d, -1, sizeof d);
    xa[0] = 0; ya[0] = 0;
    xa[1] = 0, ya[1] = m-1;
    for(int i = 0; i<2; i++) {
      queue< pair<int, int> > que;
      que.push({xa[i], ya[i]});
      d[i][xa[i]][ya[i]] = 0;
      while(!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        int lol = min(x+k[i], n-1);
        for(int j = max(0, x-k[i]); j<=lol; j++) {
          int res = k[i]-abs(j-x);
          int lol2 = min(y+res, m-1);
          for(int h = max(0, y-res); h <= lol2; h++) if(d[i][j][h] == -1 && s[j][h] == 0) {
            d[i][j][h] = d[i][x][y] + 1;
            que.push({j, h});
          }
        }
      }
    }
    int ans = inf;
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++)
        if(d[0][i][j] >= 0 && d[1][i][j] >= 0) {
          ans = min(ans, max(d[0][i][j], d[1][i][j]));
        }
    if(ans == inf)
      ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}