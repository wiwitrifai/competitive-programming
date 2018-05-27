#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      bool ok = 0;
      for (int k = i, l = j; k < j; ++k, --l) {
        if (s[k] != s[l]) {
          ok = 1;
          break;
        }
      }
      if (ok)
        ans = max(ans, j-i+1);
    }
  }
  printf("%d\n", ans);
  return 0;
}