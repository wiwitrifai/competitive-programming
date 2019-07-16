#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N][N], tmp[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  if (n > m) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        tmp[j][i] = s[i][j];
    swap(n, m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        s[i][j] = tmp[i][j];
  }
  int ans = 0;
  if (n == 1) {
    for (int i = 1; i < m-1; ++i)
      ans += s[0][i] != '#';
  }
  else if (n == 2) {
    for (int i = 1; i < m-1; ++i) {
      if (s[0][i] == '.' && s[1][i] == '.') {
        ++ans;
      }
    }
  }
  else {
    for (int i = 1; i < n-1; ++i)
      for (int j = 1; j < m-1; ++j)
        ans += s[i][j] != '#';
    bool ada = 0;
    for (int i = 1; i < n-1; ++i)
      ada |= (s[i][0] == '#') || (s[i][m-1] == '#');
    for (int i = 1; i < m-1; ++i)
      ada |= (s[0][i] == '#') || (s[n-1][i] == '#');
    ans += !ada;
  }
  printf("%d\n", ans);
  return 0;
}