#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), a[i] = abs(a[i]);
  sort(a, a+n);
  long long ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < i && a[j] * 2 < a[i]) ++j;
    ans += i - j;
  }
  printf("%lld\n", ans);
  return 0;
}
