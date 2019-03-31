#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  long long n, k, a, b;
  cin >> n >> k >> a >> b;
  long long tot = 1LL * n * k;
  long long ans1 = 1LL * n * k, ans2 = 0;
  long long s = a;
  for (int i = 0; i < n; ++i) {
    long long t = 1LL * i * k + b;
    long long d = (t - s) % tot;
    if (d < 0) d += tot;
    long long cur = tot / gcd(d, tot);
    ans1 = min(ans1, cur);
    ans2 = max(ans2, cur);

    t = 1LL * i * k - b;
    d = (t - s) % tot;
    if (d < 0) d += tot;
    cur = tot / gcd(d, tot);
    ans1 = min(ans1, cur);
    ans2 = max(ans2, cur);
  }
  s = (k-a) % k;
  for (int i = 0; i < n; ++i) {
    long long t = 1LL * i * k + b;
    long long d = (t - s) % tot;
    if (d < 0) d += tot;
    long long cur = tot / gcd(d, tot);
    ans1 = min(ans1, cur);
    ans2 = max(ans2, cur);

    t = 1LL * i * k - b;
    d = (t - s) % tot;
    if (d < 0) d += tot;
    cur = tot / gcd(d, tot);
    ans1 = min(ans1, cur);
    ans2 = max(ans2, cur);
  }
  printf("%lld %lld\n", ans1, ans2);
  return 0;
}
