#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k, t;
  scanf("%d %d %d", &n, &k, &t);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  int bef = 1, aft = 0;
  while (bef <= k-1 && a[k-1-bef] == a[k-1]) ++bef;
  while (k+aft < n && a[k+aft] == a[k-1]) ++aft;
  int ans = n+1;
  if (a[k-1] < t || aft == 0)
    ans = min(ans, aft);
  if (a[k-1] > 0)
    ans = min(ans, bef);
  if (ans > n) {
    puts("-1");
    return 0;
  }
  printf("%d\n", ans);
  return 0;
}