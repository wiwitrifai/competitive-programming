#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}
long long lcm(long long a, long long b) {
  return (a / gcd(a, b)) * b;
}
long long a[505];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%lld", a+i);
    long long ans = lcm(a[0], a[1]);
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        ans = min(ans, lcm(a[i], a[j]));
    printf("%lld\n", ans);
  }
  return 0;
}