#include <bits/stdc++.h>

using namespace std;
int a[12345], cnt[12345];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  map< int, int  > m;
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
    if(m.count(a[i]-d))
      cnt[i] = m[a[i]-d];
    else
      cnt[i] = 0;
    ++m[a[i]];
  }
  m.clear();
  for(int i = n-1; i>= 0; i--) {
    if(m.count(a[i]+d))
      ans += 1LL*cnt[i] * m[a[i]+d];
    ++m[a[i]];
  }
  printf("%lld\n", ans);
  return 0;
}