#include <bits/stdc++.h>

using namespace std;

const int M = 4;
bool vis[9][9];

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

map<long long, long long > mp[8][8];
char s[22], b[22][22];
int n;
void dfs(int id, int x, int y, long long mask) {
  if (min(x, y) < 0 || max(x, y) >= 8) return;
  if (id >= n) return;
  if (vis[x][y]) return;
  if (s[id] != b[x][y]) return;
  mask |= 1LL << (x * 8 + y);
  if (id == n-1) {
    mp[x][y][mask]++;
    return;
  }
  vis[x][y] = 1;
  for (int j = 0; j < 8; j++)
    dfs(id+1, x + dx[j], y + dy[j], mask);
  vis[x][y] = 0;
  return;
}

vector<pair<long long, long long> > bac[8][8];

int main() {
  int k;
  scanf("%d %s", &k, s);
  for (int i = 0; i < 8; i++)
    scanf("%s", b[i]);
  memset(vis, 0, sizeof vis);
  n = (k+1)/2;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      dfs(0, i, j, 0);
    }
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      long long cur = 1LL << (i * 8 + j);
      for (auto it : mp[i][j])
        bac[i][j].push_back(make_pair(it.first^cur, it.second));
      mp[i][j].clear();
    }
  reverse(s, s+k);
  n = k- n+1;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      dfs(0, i, j, 0);
    }
  long long ans = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (auto it : mp[i][j]) {
        for (auto it2 : bac[i][j]) {
          if (it.first & it2.first) continue;
          ans += it.second * it2.second;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}