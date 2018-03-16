#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const long long inf = 1e18;

int e[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", e+i);
  sort(e, e+n);
  long long ans = 0;
  for (int i = 0; i + 1 < n; ++i)
    ans += 1LL * e[i] * e[i+1];
  printf("%lld\n", ans);
  return 0;
}