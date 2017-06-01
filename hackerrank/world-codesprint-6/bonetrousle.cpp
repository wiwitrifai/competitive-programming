#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k, b;
    cin >> n >> k >> b;
    long long sum = b * (b + 1) / 2;
    if (n < sum || ((2LL * k - b + 1) < ((2 * n + b - 1) / b)))
      puts("-1");
    else {
      long long diff = n - sum, ma = k - b;
      for (long long i = b; i; i--) {
        long long d = min(diff, ma);
        diff -= d;
        printf("%lld", i + d);
        if (i > 1)
          printf(" ");
      }
      assert(diff == 0);
      printf("\n");
    }
  }

  return 0;
}