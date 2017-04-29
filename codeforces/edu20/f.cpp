#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

int a[N], c[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    c[a[i]]++;
  }
  for (int i = 1; i < N; i++) {
    for (int j = i+i; j < N; j += i) if (c[j])
      c[i] += c[j];
    if (c[i])
      c[i] = powmod(2, c[i]) - 1;
  }
  for (int i = N-1; i > 0; i--) {
    for (int j = i + i; j < N; j += i) if (c[j]) {
      c[i] -= c[j];
      if (c[i] < 0) c[i] += mod;
    }
  }
  c[1] %= mod;
  if (c[1] < 0) c[1] += mod;
  printf("%d\n", c[1]);
  return 0;
}