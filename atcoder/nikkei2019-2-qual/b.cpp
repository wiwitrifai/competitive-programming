#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 998244353;

int cnt[N], d[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", d+i);
    ++cnt[d[i]];
  }
  for (int i = 1; i < n; ++i) {
    if (d[i] == 0) {
      puts("0");
      return 0;
    }
  }
  if (d[0] != 0) {
    puts("0");
    return 0;
  }
  long long ans = 1;
  for (int i = 1; i < n; ++i) {
    int c = cnt[d[i]-1];
    ans = (ans * c) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
