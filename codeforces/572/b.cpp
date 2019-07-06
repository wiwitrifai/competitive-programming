// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, p, k;

int a[N];

long long powmod(long long b, long long x) {
  long long r = 1;
  for (; x; x >>= 1, b = b * b % p)
    if (x & 1)
      r = r * b % p;
  return r;
}

int main() {
  scanf("%d %d %d", &n, &p, &k);
  vector<int> val(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    long long now = powmod(a[i], 4) - 1LL * k * a[i];
    now %= p;
    if (now < 0)
      now += p;
    val[i] = now;
  }
  sort(val.begin(), val.end());
  long long ans = 0;
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && val[j] == val[i]) ++j;
    int cnt = j - i;
    ans += 1LL * cnt * (cnt - 1) / 2;
    i = j;
  }
  printf("%lld\n", ans);
  return 0;
}
