#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<long long> a(n), b(m);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  for (int i = 0; i < m; ++i)
    scanf("%lld", &b[i]);
  long long all = 0;
  for (int i = 0; i + 1 < n; ++i) {
    all = gcd(all, abs(a[i+1]-a[i]));
  }
  for (int i = 0; i < m; ++i) {
    long long ans = gcd(all, a[0]+b[i]);
    printf("%lld%c", ans, i+1 == m ? '\n' : ' ');
  }
  return 0;
}
