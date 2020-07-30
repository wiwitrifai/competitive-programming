#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int cnt[10];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    s[i] -= '0';
    ++cnt[s[i]];
  }
  int ans = 0;
  for (int i = 0; i < 10; ++i)
    ans = max(ans, cnt[i]);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (j == i) continue;
      int cur = 0;
      for (int k = 0; k < n; ++k) {
        if (cur & 1) {
          if (s[k] == i)
            ++cur;
        } else {
          if (s[k] == j)
            ++cur;
        }
      }
      if (cur & 1)
        --cur;
      ans = max(ans, cur);
    }
  }
  printf("%d\n", n - ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
