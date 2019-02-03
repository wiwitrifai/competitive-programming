#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int len;
    scanf("%d %s", &len, s);
    int n = 0;
    for (int i = 0; i < len; ++i) {
      if (s[i] == '#')
        a[n++] = i;
    }
    for (int i = 0; i < n; ++i) {
      b[i] = a[i];
      if (a[i] == i) continue;
      if (i) {
        b[i] = max(b[i-1] + 2, a[i]);
      }
    }
    if (n > 0 && (b[n-1] >= len-1 && b[n-1] != n-1)) {
      puts("-1");
    }
    else {
      long long ans = 0;
      for (int i = 0; i < n; ++i) {
        ans += b[i] - a[i] + b[i] - i;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}