#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  scanf("%d", &n);
  int k = (n + 1) / 2;
  vector<int> a(n);
  for (int i = 0; i < k; ++i)
    scanf("%d", &a[i]);
  scanf("%d", &x);
  for (int i = k; i < n; ++i)
    a[i] = x;
  vector<long long> pref(n+1);
  pref[0] = 0;
  for (int i = 0; i < n; ++i) {
    pref[i+1] = pref[i] + a[i];
  }
  int s = n - k;
  long long maxi = -1e18;
  int ans = -1;
  for (int i = 0; i <= s; ++i) {
    long long cur = pref[i] - 1LL * i * x;
    if (i)
      maxi = max(maxi, cur);
    else
      maxi = cur;
    if (maxi < pref[n-i]) {
      ans = n - i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
