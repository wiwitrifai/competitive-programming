#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
char s[55][55];
bool vis[55][55];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n;

bool fill(int x, int y, char c) {
  if (x < 0 || x >= n || y < 0 || y >= n) return 1;
  if (s[x][y] == '.' || s[x][y] == c) return 1;
  if (s[x][y] != '?') return 0;
  s[x][y] = c;
  bool ret = 1;
  for (int k = 0; k < 4; k++) {
    ret &= fill(x+dx[k], y+dy[k], c);
  }
  return ret;
}
int get(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return 0;
  if (s[x][y] != '?') return 0;
  s[x][y] = '.';
  int ret = 1;
  for (int k = 0; k < 4; k++) {
    ret += get(x+dx[k], y+dy[k]);
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%s", s[i]);
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '.') continue;
        if (s[i][j] == 'G') {
          for (int k = 0; k < 4; k++) {
            int xx = i + dx[k], yy = j + dy[k];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
            if (s[xx][yy] != '.')
              ok = 0;
          }
        }
        else if (s[i][j] != '?') {
          char now = s[i][j];
          s[i][j] = '?';
          ok &= fill(i, j, now);
        }
      }
    }
    int one = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] != '?') continue;
        int now = get(i, j);
        if (now == 1)
          one++;
        else
          cnt++;
      }
    }
    long long ans = ok;
    while (one--) ans = (ans * 3) % mod;
    while (cnt--) ans = (ans * 2) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}