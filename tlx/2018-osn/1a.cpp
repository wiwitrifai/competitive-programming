#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int a[N], b[N], h[N];
int cnt[N], la[N], lb[N], ua[N], ub[N];
int fac[N];

int calc(int lowa, int upa, int lowb, int sameb, int upb) {
  if (lowa > upb + sameb) return 0;
  if (upa > lowb + sameb) return 0;
  return 1LL * fac[lowa] * fac[upa] % mod; 
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = 1LL * fac[i-1] * i % mod;
  int n, k;
  scanf("%*s");
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; ++i)
    scanf("%d", h+i), --h[i];
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i); --a[i];
    ++cnt[a[i]];
    if (i < h[a[i]])
      ++la[a[i]];
    else if (i > h[a[i]])
      ++ua[a[i]];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i); --b[i];
    if (i < h[b[i]])
      ++lb[b[i]];
    else if (i > h[b[i]])
      ++ub[b[i]];
  }
  int ans = 1;
  for (int i = 0; i < k; ++i) {
    int samea = cnt[i] - la[i] - ua[i];
    int sameb = cnt[i] - lb[i] - ub[i];
    int cur = 0;
    if (samea) {
      if (lb[i])
        cur = (cur + 1LL * lb[i] * calc(la[i], ua[i], lb[i]-1, sameb, ub[i])) % mod;
      if (sameb)
        cur = (cur + calc(la[i], ua[i], lb[i], sameb-1, ub[i])) % mod;
      if (ub[i])
        cur = (cur + 1LL * ub[i] * calc(la[i], ua[i], lb[i], sameb, ub[i]-1)) % mod;
    }
    else {
      cur += calc(la[i], ua[i], lb[i], sameb, ub[i]);
    }
    ans = (1LL * ans * cur) % mod;
  }
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
  return 0;
}