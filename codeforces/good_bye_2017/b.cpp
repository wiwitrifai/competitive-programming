#include <bits/stdc++.h>

using namespace std;

const int N = 550;

char s[N][N];
char c[N];
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int mp[5];
int len;

int cek() {
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'S')
        x = i, y = j;
    }
  }
  for (int i = 0; i < len; ++i) {
    int dir = mp[c[i]];
    x += dx[dir], y += dy[dir];
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (s[x][y] == '#') return 0;
    if (s[x][y] == 'E') return 1;
  }
  return 0;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  scanf("%s", c);
  len = strlen(c);
  for (int i = 0; i < len; ++i)
    c[i] -= '0';
  for (int i = 0; i < 4; ++i)
    mp[i] = i;
  int ans = 0;
  do {
    ans += cek();
  } while (next_permutation(mp, mp+4));
  printf("%d\n", ans);
  return 0;
}