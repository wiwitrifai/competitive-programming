#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int p[N];
int cnt[N], a[N];

int main() {
  p[0] = p[1] = 1;
  for (int i = 2; i < N; i++) if (p[i] == 0) {
    p[i] = i;
    for (long long j = 1LL * i * i; j < N; j+= i)
      if (p[j] == 0)
        p[j] = i; 
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      int now = a[i];
      while (now > 1) {
        int pp = p[now];
        int tmp = 0;
        while ((now % pp) == 0) {
          now /= pp;
          tmp ^= 1;
        }
        if (tmp) {
          ans -= min(n-cnt[pp], cnt[pp]);
          cnt[pp]++;
          ans += min(n-cnt[pp], cnt[pp]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      int now = a[i];
      while (now > 1) {
        int pp = p[now];
        while ((now % pp) == 0) {
          now /= pp;
        }
        cnt[pp] = 0;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}