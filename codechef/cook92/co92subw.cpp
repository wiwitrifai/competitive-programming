#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    int le = 0, ri = 1e5;
    while (le < ri) {
      int mid = (le+ri+1) >> 1;
      long long d = 1LL * mid * (mid + 1) / 2;
      if (d <= x)
        le = mid;
      else
        ri = mid-1;
    }
    long long cur = 1LL * (le) * (le + 1) / 2;
    long long ans = min(le+abs(x - cur), le+1+abs(cur + le+1-x));
    printf("%lld\n", ans  );
  }
  return 0;
}