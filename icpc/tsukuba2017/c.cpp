// solved by luqman
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
 
long long a[N], s[N];
long long pre[N], suf[N], best[N];
 
long long find(int l, int r) {
  if (l > r) return 0;
  return s[r] - s[l-1];
}
 
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    s[i] = s[i - 1] + a[i];
  }
  int maxi = -1, p = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > maxi) {
      maxi = a[i];
      p = i;
    }
    pre[i] = find(1, p - 1);
    suf[i] = find(p + 1, i);
    best[i] = maxi;
  }
  for (int i = 1; i <= n; i++) {
    long long l = 1, r = 2e9;
    while (l < r) {
      long long ke = (l + r) >> 1;
      long long tot = pre[i] + suf[i] + best[i] * ke;
      if (t < tot) {
        r = ke;
      } else {
        l = ke + 1;
      }
    }
    printf("%lld\n", l);
  }
  return 0;
}