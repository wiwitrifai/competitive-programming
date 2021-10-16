/**
 *  Coded by Luqman
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, p;
    scanf("%d %d", &n, &p);
    long long all = (1LL << n) - 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      long long now = (1LL << (i - 1));
      if (now <= p) {
        ans++;
        all -= now;
      } else {
        ans += (all + p - 1) / p;
        break;
      }
    } 
    printf("%lld\n", ans);
  }

  return 0;
}
