#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
char ans[N];

void solve() {
  int x;
  scanf("%s %d", s, &x);
  int n = strlen(s);
  for (int i = 0; i < n; ++i)
    ans[i] = '1';
  ans[n] = '\0';
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (i >= x) {
        ans[i-x] = '0';
      }
      if (i+x < n) {
        ans[i+x] = '0';
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    char cur = '0';
    if (i >= x && ans[i-x] == '1')
      cur = '1';
    if (i+x < n && ans[i+x] == '1')
      cur = '1';
    ok &= s[i] == cur;
  }
  if (!ok) {
    puts("-1");;
  } else {
    printf("%s\n", ans);
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
