#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

char s[N], p[5];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s %s", &n, s, p);
    int ans = 1;
    if (p[0] == 'T' || p[0] == 'B') {
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'T' || s[i] == 'B') continue;
        ans = (ans * 2) % mod;
      }
    }
    else {
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'L' || s[i] == 'R') continue;
        ans = (ans * 2) % mod;
      }
    }
    ans = (ans + 1) % mod;
    printf("%d\n", ans);
  }
  return 0;
}