#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  while (q--) {
    int k;
    scanf("%d", &k);
    long long tot = k * 3LL;
    long long ans = tot / n;
    printf("%lld\n", ans);
  }
  return 0;
}
