#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ans = 0, cnt = 0;
  int bad = 0;
  for (int i = 0; i < n; ++i) {
    cnt += s[i] == '(' ? 1 : -1;
    if (cnt < 0)
      bad = 1;
  }
  ans += bad;
  cnt = bad = 0;
  for (int i = n-1; i >= 0; --i) {
    cnt += s[i] == ')' ? 1 : -1;
    if (cnt < 0)
      bad = 1;
  }
  ans += bad;
  printf("%d\n", ans);
  return 0;
}