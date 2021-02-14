#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];

int cnt[4];

char dir[] = "LRDU";

void solve() {
  int x, y;
  scanf("%d %d", &x, &y);
  scanf("%s", s);
  int n = strlen(s);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (s[i] == dir[j]) {
        ++cnt[j];
      }
    }
  }
  puts((-cnt[0] <= x && x <= cnt[1]) && (-cnt[2] <= y && y <= cnt[3]) ? "YES" : "NO");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
