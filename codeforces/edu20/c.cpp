#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  if (k > 1e6) {
    puts("-1");
    return 0;
  }
  long long ans = -1;
  long long mi = k * (k + 1) / 2;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i) continue;
    long long x = n/i;
    if (x >= mi)
      ans = max(ans, i);
    if (i >= mi)
      ans = max(ans, x);
  }
  if (ans <= 0)
    puts("-1");
  else {
    for (int i = 1; i < k; i++) {
      printf("%I64d ", 1LL * i * ans);
      n -= ans * i;
    }
    printf("%I64d\n", n);
  }
  return 0;
}