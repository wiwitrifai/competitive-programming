#include <bits/stdc++.h>

using namespace std;

const int N = 128;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] != '*') continue;
      if (s[i+1][j] == '*') continue;
      if (s[i][j+1] == '*') continue;
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
