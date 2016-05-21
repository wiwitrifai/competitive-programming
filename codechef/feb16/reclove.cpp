#include <bits/stdc++.h>

using namespace std;

int t, n, m, k;


int main() {
  scanf("%d", &t);
  cout << fixed << setprecision(20);
  while(t--) {
    scanf("%d%d%d", &n, &m, &k);
    long double ans = 0, div1 = 1LL*n*(n+1)/2LL, div2 = 1LL*m*(m+1)/2LL;
    while(k--) {
      long long v;
      scanf("%lld", &v);
      v--;
      long long x = v/m, y = v % m;
      ans += ((long double)(x+1)*(y+1)/div1)*((long double)(n-x)*(m-y)/div2);
    }
    cout << ans << "\n";
  }
  return 0;
}