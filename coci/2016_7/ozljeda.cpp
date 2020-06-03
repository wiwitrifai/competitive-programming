#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long x[N];

int main() {
  scanf("%d", &n);
  x[0] = 0;
  for(int i = 0; i<n; i++) {
    long long v;
    scanf("%lld", &v);
    x[i+1] = x[i] ^ v;
  }
  n++;
  x[n] = 0;
  int q;
  scanf("%d", &q);
  while(q--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    l %= n;
    if(l == 0)
      l = n;
    r %= n;
    if(r == 0)
      r = n;
    printf("%lld\n", x[r]^x[l-1]);
  }
  return 0;
}