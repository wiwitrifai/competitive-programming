#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[i]);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int val = a[i] ^ b[i];
    if ((val & c[i]) == c[i])
      val ^= c[i] & -c[i];
    else
      val |= c[i];
    ans += val;
  }
  printf("%lld\n", ans);
  return 0;
}
