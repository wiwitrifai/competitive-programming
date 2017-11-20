#include <bits/stdc++.h>


using namespace std;

const int N = 1024;

int a[N][N];

bool vis[N][N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, pair<int, int> > > vp;
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < m; j++) {
        scanf("%d", a[i]+j);
        vp.push_back({-a[i][j], {i, j}});
        vis[i][j] = 0;
      }
    sort(vp.begin(), vp.end());
    int ans = 0;
    for (auto it : vp) {
      int x = it.second.first, y = it.second.second;
      if (vis[x][y]) continue;
      ans++;
      queue<pair<int, int> > q;
      q.push(make_pair(x, y));
      vis[x][y] = 1;
      while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
          int xx = x + dx[i], yy = y + dy[i];
          if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
          if (vis[xx][yy]) continue;
          if (a[xx][yy] > a[x][y]) continue;
          vis[xx][yy] = 1;
          q.push(make_pair(xx, yy));
        }
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}