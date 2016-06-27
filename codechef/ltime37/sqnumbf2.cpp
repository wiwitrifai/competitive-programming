#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 6, M = 8e4 + 5;
 
bitset<N> bs;
bitset<M> occ;
vector< int > prime;
int n;
long long a[202];
 
long long gcd(long long x, long long y) {
  return x ? gcd( y % x, x) : y;
}
 
int main() {
  bs.set();
  bs[0] = bs[1] = 0;
  for(int i = 2; i<N; i++) if(bs[i]) {
    for(long long j = 1LL*i*i; j<N; j+= i)
      bs[j] = 0;
    prime.push_back(i);
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    occ.reset();
    for(int i = 0; i<n; i++) {
      scanf("%lld", a+i);
    }
    set< long long > st;
    long long ans = -1;
    for(int i = 0; i<n && ans < 0; i++) {
      for(int j = 0; j<prime.size() && ans < 0; j++) {
        int p = prime[j];
        if((a[i] % p) == 0) {
          if(occ[j])
            ans = p;
          else {
            a[i] /= p;
            if((a[i] % p) == 0)
              ans = p;
            occ[j] = 1;
          }
        }
      }
      if(a[i] > 1) {
        if(st.count(a[i]))
          ans = a[i];
        st.insert(a[i]);
      }
    }
    for(int i = 0; i<n && ans < 0; i++) if(a[i] > 1) {
      long long l = 0, r = 1e9;
      while(l < r) {
        long long mid = (l + r) >> 1;
        if(mid * mid < a[i])
          l = mid + 1;
        else
          r = mid;
      }
      if(l * l == a[i])
        ans = l;
    }
    for(int i = 0; i<n && ans < 0; i++) {
      for(int j = i+1; j<n && ans < 0; j++) {
        long long g = gcd(a[i], a[j]);
        if(g > 1)
          ans = g;
      }
    }
    assert(ans > 1);
    printf("%lld\n", ans);
  } 
 
  return 0;
} 