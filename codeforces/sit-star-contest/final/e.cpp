#include <bits/stdc++.h>

using namespace std;

const int N = 202;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  char last = 'A';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '.') continue;
      char cur = last;
      if (i > 0 && s[i-1][j] != '.')
        cur = s[i-1][j];
      if (j > 0 && s[i][j-1] != '.')
        cur = s[i][j-1];
      s[i][j] = cur;
      last += cur == last;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%s\n", s[i]);
  }
  return 0;
}
