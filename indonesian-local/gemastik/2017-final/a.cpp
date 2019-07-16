#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      ans = max(ans, (long long)a);
      sum += a;
    }
    ans = max(ans, (sum + k-1)/ k);
    printf("%lld\n", ans);
  }
  return 0;
}