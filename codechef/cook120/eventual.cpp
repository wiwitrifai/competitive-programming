#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];
int cnt[26];

void solve() {
  int n;
  scanf("%d %s", &n, s);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  bool ok = true;
  for (int i = 0; i < 26; ++i)
    ok &= (cnt[i] & 1) == 0;
  puts(ok ? "YES" : "NO");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
