#include <bits/stdc++.h>

using namespace std;
const long long inf = 1e13 + 7;

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    sum += a;
  }
  int m;
  scanf("%d", &m);
  long long ans = inf;
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (sum <= l)
      ans = min(ans, (long long)l);
    if (l <= sum && sum <= r)
      ans = min(ans, sum);
  }
  if (ans >= inf)
    ans = -1;
  printf("%I64d\n", ans);
  return 0;
}