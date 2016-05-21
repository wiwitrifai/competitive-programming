#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5; 

int n, k;
int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n; i++) {
      scanf("%d", a+i);
    }
    for(int i = 0; i<n; i++) {
      scanf("%d", b+i);
    }
    int ma = abs(b[0]);
    for(int i = 0; i<n; i++) {
      ans += 1LL*a[i]*b[i];
      ma = max(ma, abs(b[i]));
    }
    ans += 1LL*ma*k;
    printf("%lld\n", ans);
  }  
  return 0;
}