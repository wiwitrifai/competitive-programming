#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  int ma = a[0], mb = b[0];
  long long ans = 1LL * a[0] * b[0];
  for (int i = 0; i < n; ++i) {
    ma = max(ma, a[i]);
    ans = max(ans, 1LL * ma * b[i]);
    printf("%lld\n", ans);
  }
  return 0;
}
