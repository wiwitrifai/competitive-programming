#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int n, a[N];
long long b[N], c[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
      scanf("%d", a+i);
    long long d, e;
    d = e = 0;
    for(int i = 0; i<n; i++) {
      if(i & 1)
        d += a[i];
      else
        e += a[i];
      b[i] = d;
      c[i] = e;
    }
    long long ans = e;
    if((n & 1) == 0) {
      ans = max(d, e);
      cout << ans << endl;
      continue;
    }
    d = e = 0;
    for(int i = n-1; i>0; i--) {
      if(i & 1) {
        d += a[i];
        ans = max(ans, d + c[i-1]);
      }
      else {
        e += a[i];
        ans = max(ans, e + b[i-1]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}