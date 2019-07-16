#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long bef = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    int cur = bef / k;
    bef -= 1LL * k * cur;
    ans += cur;
    if (bef > 0) {
      bef += a;
      ++ans;
      bef = max(0LL, bef - k);
    }
    else
      bef = a;
  }
  ans += (bef + k - 1) / k;
  printf("%lld\n", ans);
  return 0;
}