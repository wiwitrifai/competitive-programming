#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int f[N], b[N];
int cnt[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = n; i >= 1; --i) {
    if (n % i) continue;
    f[i] = n/i;
    for (int j = i+i; j <= n; j += i)
      f[i] -= f[j];
  }
  int ans = 0;
  for (int d = 1; d <= n; ++d) {
    if (n % d) continue;
    fill(cnt, cnt+d, 0);
    for (int i = 0; i < n; ++i) {
      cnt[i%d] ^= s[i]-'0';
    }
    bool ok = 1;
    for (int i = 0; i < d; ++i)
      if (cnt[i]) {
        ok = 0;
        break;
      }
    if (ok)
      ans += f[d];
  }
  printf("%d\n", ans);
  return 0;
}
