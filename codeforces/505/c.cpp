#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; ++i)
    s[i+n] = s[i];
  int ans = 1;
  int cnt = 1;
  for (int i = 1; i < 2 * n; ++i) {
    if (s[i] != s[i-1]) {
      ++cnt;
    }
    else
      cnt = 1;
    ans = max(ans, cnt);
  }
  ans = min(ans, n);
  printf("%d\n", ans);
  return 0;
}