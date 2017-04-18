#include <bits/stdc++.h>

using namespace std;

const int N = 11;
int a[N], cnt[N];

bool cek(long long x) {
  for (int i = 0; i < 10; i++) cnt[i] = 0;
  while (x) {
    cnt[x % 10]++;
    x /= 10;
  }
  for (int i = 0; i < 10; i++)
    if (a[i] == cnt[i])
      return 0;
  return 1;
}
long long dp[1 << 10];
long long mul[10];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    for (int i = 0; i < 10; i++)
      scanf("%d", a+i);
    if (r-l < 1e6) {
      int ans = 0;
      for (long long i = l; i <= r; i++)
        ans += cek(i);
      printf("%d\n", ans);
    }
    else {
      for (int i = 0; i < (1<<10); i++) {
        long long cur = 1, sum = 0, mask = 0;
        for (int j = 0; j < 10; j++) if (i & (1<<j)) {
          mul[j] = cur;
          mask += cur * a[j];
          cur *= a[j]+1;
          sum += a[j];
        }
        else
          mul[j] = 0;
        if (sum > 18)
          dp[i] = 0;
        else {
          dp[i] = get(r, mask) - get(l-1, mask);
        }
      }   
    }
  }
  return 0;
}