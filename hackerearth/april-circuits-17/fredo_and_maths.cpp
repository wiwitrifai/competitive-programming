#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 6;

int euler[N];
long long powmod(long long b, long long p, long long m) {
  long long ret = 1;
  for (; p; p >>= 1, b = b*b % m)
    if (p & 1) ret = ret * b % m;
  return ret;
}
long long solve(long long x, long long k, long long m) {
  if (m == 1) return 0;
  if (k == 1) return x % m;
  return powmod(x, solve(x, k-1, euler[m]), m);
}

int main() {
  for (int i = 0; i < N; i++)
    euler[i] = i;
  for (int i = 2; i < N; i++) if (euler[i] == i) {
    for (int j = i; j < N; j += i)
      euler[j] -= euler[j]/i;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x, k, m;
    scanf("%lld %lld %lld", &x, &k, &m);
    printf("%lld\n", solve(x, k, m));
  }
  return 0;
}