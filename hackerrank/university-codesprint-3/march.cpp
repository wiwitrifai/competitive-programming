#include <bits/stdc++.h>

using namespace std;

const int M = 4;
bool vis[9][9];

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

map<long long, long long > mp[8][8];
char s[22], b[22][22];
int n;
long long dfs(int id, int x, int y, long long mask) {
  if (min(x, y) < 0 || max(x, y) >= 8) return 0;
  if (id >= n) return 0;
  if (vis[x][y]) return 0;
  if (s[id] != b[x][y]) return 0;
  if (id == n-1) return 1;
  mask |= 1LL << (x * 8 + y);
  if (id == M) {
    auto it = mp[x][y].find(mask);
    if (it != mp[x][y].end())
      return it->second;
  }
  vis[x][y] = 1;
  long long ans = 0;
  for (int j = 0; j < 8; j++)
    ans += dfs(id+1, x + dx[j], y + dy[j], mask);
  if (id == M)
    mp[x][y][mask] = ans;
  vis[x][y] = 0;
  return ans;
}

int main() {
  scanf("%d %s", &n, s);
  for (int i = 0; i < 8; i++)
    scanf("%s", b[i]);
  long long ans = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      memset(vis, 0, sizeof vis);
      ans += dfs(0, i, j, 0);
    }
  printf("%lld\n", ans);
  return 0;
}