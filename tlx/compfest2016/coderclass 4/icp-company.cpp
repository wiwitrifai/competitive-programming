#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int p[N], te[N], bef[N];
int add[N], sub[N];

int main() {
  for (int i = 2; i < N; i++) if (p[i] == 0) {
    p[i] = i;
    for (long long j = 1L * i * i; j < N; j += i)
      if (p[j] == 0)
        p[j] = i;
  }
  te[1] = 1;
  for (int i = 2; i < N; i++) {
    int pp = p[i];
    int pa = 1;
    int now = i / pp;
    while ((now % pp) == 0) {
      pa *= pp;
      now /= pp;
    }
    te[i] = te[now] * pa * (pp - 1);
    bef[i] = now;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    long long ans = 0;
    int aa = a, bb = b;
    add[1] = bb;
    sub[1] = 0;
    for (int i = 2; i<=aa; i++) {
      int pp = p[i];
      int now = bef[i];
      add[i] = add[now] + (sub[now]/pp);
      sub[i] = sub[now] + (add[now]/pp);
    }
    for(int d = 1; d <= a; d++) {
      aa = a/d; bb = b/d;
      ans = (ans - bb + 1) % mod;
      for(int i = 2; i<= aa; i++) {
        int cnt = add[i]/d - (sub[i]/d);
        ans += (1LL * (2 * te[i] - cnt) * i) % mod;
        ans %= mod;
      }
    }
    aa = a; bb = b;
    add[1] = aa;
    sub[1] = 0;
    for (int i = 2; i<=bb; i++) {
      int pp = p[i];
      int now = bef[i];
      add[i] = add[now] + (sub[now]/pp);
      sub[i] = sub[now] + (add[now]/pp);
    }
    for (int d = 1; d <= a; d++) {
      aa = a/d; bb = b/d;
      for (int i = aa+1; i<=bb; i++) {
        int cnt = add[i]/d - (sub[i]/d);
        ans += (1LL * cnt * i) % mod;
        ans %= mod;
      }
    }
    ans %= mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }

  return 0;
}