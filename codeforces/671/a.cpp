#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];

void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int ans = 2;
  if (n & 1) {
    ans = 2;
    for (int i = 0; i < n; i += 2) {
      if ((s[i] - '0') & 1)
        ans = 1;
    }
  } else {
    ans = 1;
    for (int i = 1; i < n; i += 2) {
      if (((s[i] - '0') & 1) == 0) {
        ans = 2;
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
