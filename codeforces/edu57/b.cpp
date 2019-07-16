#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 998244353;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int a = 1, b = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[0])
      ++a;
    else
      break;
  }
  for (int i = n-2; i >= 0; --i) {
    if (s[i] == s[n-1])
      ++b;
    else
      break;
  }
  if (s[0] == s[n-1]) {
    printf("%d\n", (1LL * (a + 1) * (b + 1)) % mod);
  }
  else
    printf("%d\n", (a + b + 1) % mod);
  return 0;
}