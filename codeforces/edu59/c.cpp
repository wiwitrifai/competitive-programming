#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], n, k;
char s[N];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  scanf("%s", s);
  int j = 0;
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (s[i] != s[j]) {
      sort(a+j, a+i);
      for (int x = 1; x <= min(k, i-j); ++x)
        ans += a[i-x];
      j = i;
    }
  }
  assert(j == n);
  printf("%lld\n", ans);
  return 0;
}