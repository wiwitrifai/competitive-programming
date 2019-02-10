#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i), a[i] -= b[i];
  sort(a, a+n);
  int cnt = 0, ans = 0, last = 0;
  for (int i = 0; i < n; ++i) {
    if (last != a[i])
      last = a[i], cnt = 0;
    ++cnt;
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}