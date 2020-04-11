#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long sum = k * k;
    puts((n >= sum && (((n - sum) & 1) == 0)) ? "YES" : "NO");
  }
  return 0;
}
