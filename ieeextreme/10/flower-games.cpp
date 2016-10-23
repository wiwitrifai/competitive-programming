/**
  IEEExtreme Programming Contest 10
  Problem : Flower Games
  Solver  : Luqman Arifin S
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    for (int i = 62; i >= 0; i--) {
      if (n & (1LL << i)) {
        n -= (1LL << i) - 1;
        break;
      }
    }
    printf("%lld\n", 2 * n - 1);
  }


  return 0;
}
