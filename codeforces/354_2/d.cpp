#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int inf = 1e8;
int n, m;
char s[N][N];
int val[N][N];
int a, b, c, d;
char mp[] = {'*', '^', '>', 'X', 'v', '|', 'X', 'L', '<', 'X', '-', 'D', 'X', 'R', 'U', '+'};
int to[256];
int ds[N][N][4];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  for(int i = 0; i<16; i++)
    to[mp[i]] = i;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    scanf("%s", s[i]);
  }
  scanf("%d%d%d%d", &a, &b, &c, &d);
  a--; b--; c--; d--;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++)
      val[i][j] = to[s[i][j]];
  }
  for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++)
      for(int k = 0; k<4; k++)
        ds[i][j][k] = inf;
  set< pair<pair< int, int >, pair< int, int >> > st;
  st.insert({{0, 0}, {a, b}});
  ds[a][b][0] = 0;
  while(!st.empty()) {
    auto it = st.begin();
    int u = it->second.first, v = it->second.second, dir = it->first.second;
    st.erase(it);
    for(int i = 0; i<4; i++) {
      int x = u + dx[i], y = v + dy[i];
      if(min(x, y) < 0 || x >= n || y >= m)
        continue;
      int pos = -1;
      for(int j = 0; j<4; j++) {
        int now = (4 - dir + 4 + i - j) % 4;
        if(now < 0)
          now += 4;
        int opp = (now+2) % 4;
        if((val[u][v] & (1<<now)) && (val[x][y] & (1<<opp))) {
          int dirr = (dir + j) % 4;
          if(ds[x][y][dirr] > ds[u][v][dir] + j+1) {
            st.erase({{ds[x][y][dirr], dirr}, {x, y}});
            ds[x][y][dirr] = ds[u][v][dir] + j+1;
            st.insert({{ds[x][y][dirr], dirr}, {x, y}});
          }
        }
      }
    }
  }
  int ans = inf;
  for(int i = 0; i<4; i++)
    ans = min(ans, ds[c][d][i]);
  if(ans >= inf)
    ans = -1;
  cout << ans << endl;
  return 0;
}