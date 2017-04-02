#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

long long h[N];
int a, b, n;

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d %d %d", &n, &a, &b);
    a--; b--;
    for (int i = 0; i < n; i++)
      scanf("%lld", h+i);
    long long ans = 0, d = abs(b-a);
    for (int i = min(a, b)+1; i < max(a, b); i++) {
      int c = abs(i-b);
      long long dif = 0;
      if (h[i] > h[b]) {
        dif = (1LL * (h[i]-h[b]) * d) / c;
      }
      else {
        dif = (1LL * (h[b]-h[i]) * d + c - 1) / c;        
        dif = - dif;
      }
      ans = max(ans, h[b] + dif - h[a] + 1); 
    }
    printf("Case #%d: %lld\n", tc, ans);
  }
  return 0;
}