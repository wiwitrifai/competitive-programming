#include <bits/stdc++.h>

using namespace std;

char s[100][100];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%s", s[i]+1);
  int r = 1, c = 1;
  bool ok = true;
  while (1) {
    if (s[r][c] != '#') {
      ok = false;
      break;
    }
    s[r][c] = '.';
    if (r == n && c == m)
      break;
    if (s[r][c+1] == '#')
      c++;
    else
      r++;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      ok &= s[i][j] != '#';
    }
  puts(ok ? "Possible" : "Impossible");
  return 0;
}