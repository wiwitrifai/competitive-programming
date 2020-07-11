#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long lcm(long long a, long long b) {
  return (a / gcd(a, b)) * b;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> fac;
  for (int i = 2; 1LL * i * i <= n; ++i) {
    if (n % i) continue;
    fac.push_back(i);
    int x = n / i;
    if (x != i)
      fac.push_back(x);
  }
  long long ans = (n-1), a = 1, b = n-1;
  for (int x : fac) {
    long long res = lcm(n-x, x);
    if (res < ans) {
      a = n-x;
      b = x;
      ans = res;
    }
  }
  if (a > b)
    swap(a, b);
  printf("%lld %lld\n", a, b);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
