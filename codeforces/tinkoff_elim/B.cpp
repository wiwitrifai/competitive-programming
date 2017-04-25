#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char x[N][N];
bool a[N][N], b[N][N];

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool ok[4];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  pair< int, int > s, t;
  for (int i = 0; i < n; i++) {
    scanf("%s", x[i]);
    for (int j = 0; j < m; j++) {
      if (x[i][j] == 'S')
        s = {i, j};
      if (x[i][j] == 'T')
        t = {i, j};
    }
  }
  memset(ok, 1, sizeof ok);
  for (int i = 0; i <= max(n, m); i++) {
    for (int j = 0; j < 4; j++) {
      if (!ok[j]) continue;
      int xx = s.first+dx[j]*i, yy = s.second+dy[j] * i;
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (x[xx][yy] == '*') {
        ok[j] = 0;
        continue;
      }
      a[xx][yy] = 1;
    }
  }
  memset(ok, 1, sizeof ok);
  for (int i = 0; i <= max(n, m); i++) {
    for (int j = 0; j < 4; j++) {
      if (!ok[j]) continue;
      int xx = t.first+dx[j]*i, yy = t.second+dy[j] * i;
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (x[xx][yy] == '*') {
        ok[j] = 0;
        continue;
      }
      b[xx][yy] = 1;
    }
  }
  bool ans = 0;
  for (int i = 0; i < n; i++) {
    bool fa = 0, fb = 0;
    for (int j = 0; j < m; j++) {
      if (x[i][j] == '*')
        fa = fb = 0;
      else {
        fa |= a[i][j];
        fb |= b[i][j];
      }
      if (fa && fb)
        ans = 1;
    }
  }
  for (int j = 0; j < m; j++) {
    bool fa = 0, fb = 0;
    for (int i = 0; i < n; i++) {
      if (x[i][j] == '*')
        fa = fb = 0;
      else {
        fa |= a[i][j];
        fb |= b[i][j];
      }
      if (fa && fb)
        ans = 1;
    }
  }
  puts(ans ? "YES" : "NO");
  return 0;
}