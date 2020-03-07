#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long ans = 2LL * (1LL * (n + 1) * (n-2) + 1LL * (m+1) * (m-2));
  printf("%lld\n", ans);
  return 0;
}
