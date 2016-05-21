#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e9 + 2;
const int mod = 1000000007;

long long fib[60];
map<long long, long long> ma[15], mb[15];

int main() {
  time_t begin = clock();
  fib[0] = 1;
  fib[1] = 2;
  int mtm = 21, mm = 49;
  for(int i = 2; i<50; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    if(fib[i] > inf) {
      mm = i;
      break;
    }
  }
  ma[0][0] = 1;
  for(int j = 0; j<mtm; j++) {
    for(int i = 0; i<10; i++) {
      for(auto it = ma[i].begin(); it != ma[i].end(); it++) {
        long long nx = it->first + fib[j];
        if(nx <= inf) {
          ma[i+1][nx] = (ma[i+1][nx] + it->second) % mod;
        }
      }
    }
  }
  mb[0][0] = 1;
  for(int j = mtm; j<mm; j++) {
    for(int i = 0; i<10; i++) {
      for(auto it = mb[i].begin(); it != mb[i].end(); it++) {
        long long nx = it->first + fib[j];
        if(nx <= inf) {
          mb[i+1][nx] += it->second % mod;
          mb[i+1][nx] %= mod; 
        }
      }
    }
  }
  int q, k;
  long long x;
  scanf("%d", &q);
  while(q--) {
    scanf("%lld%d", &x, &k);
    long long ans = 0;
    for(int i = 0; i<=k; i++) {
      int j = k-i;
      auto tt = mb[j].begin();
      for(auto it = --ma[i].upper_bound(x); ; it--) {
        while(tt != mb[j].end() && (tt->first + it->first) < x) tt++;
        if(tt == mb[j].end()) 
          break;
        if((tt->first + it->first) == x) {
          long long mul = it->second;
          ans += (mul * tt->second) % mod;
          ans %= mod;
        }
        if(it == ma[i].begin())
          break;
      }
    }
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}