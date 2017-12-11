#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int f[N + N];
long long sf[N + N];
long long ans[N];

int calc(int x) {
  int ret = 0;
  for (int i = 0; x; i++, x /= 10) {
    int y = x % 10;
    if (y & 1)
      ret += y;
    else
      ret -= y;
  }
  return abs(ret);
}

int main() {
  for (int i = 1; i < N + N; i++) {
    f[i] = calc(i);
    sf[i] = sf[i-1] + f[i];
  }
  for (int i = 1; i < N; i++) {
    ans[i] = ans[i-1] + 2 * (sf[2 * i] - sf[i]) - f[2 * i];
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", ans[n]);
  }
  return 0;
}