#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 7;

char s[N][M];
int n, m;

bool eq(int i, int j) {
  for (int k = 0; k < m; ++k) {
    if (s[i][k] == '?' || s[j][k] == '?') continue;
    if (s[i][k] != s[j][k])
      return false;
  }
  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < i; ++j)
      ans += eq(i, j);
  }
  printf("%lld\n", ans);
  return 0;
}