#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int pf[N];

int ans[N];

int main() {
  for (int i = 2; i < N; i++) if (pf[i] == 0) {
    pf[i] = i;
    for (long long j = 1LL * i * i; j < N; j += i)
      if (pf[j] == 0)
        pf[j] = i;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    memset(ans, 0, sizeof ans);
    int anss = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      int ma = 0;
      int now = a;
      while (now > 1) {
        int p = pf[now];
        ma = max(ma, ans[p]);
        while ((now % p) == 0) now /= p;
      }
      ma++;
      now = a;
      while (now > 1) {
        int p = pf[now];
        ans[p] = max(ma, ans[p]);
        while ((now % p) == 0) now /= p;
      }
      anss = max(anss, ma);
    }
    printf("%d\n", anss);
  }
  return 0;
}