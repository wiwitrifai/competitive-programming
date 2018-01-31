#include <bits/stdc++.h>

using namespace std;

const int N = 2018;

char s[N][N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*') cnt = 0;
      else ++cnt;
      ans += (cnt >= k);
    }
  }
  if (k > 1)
  for (int j = 0; j < m; ++j) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i][j] == '*') cnt = 0;
      else ++cnt;
      ans += cnt >= k;
    }
  }
  printf("%d\n", ans);
  return 0;
}