#include <bits/stdc++.h>

using namespace std;

map< long long , long long > mp;

int main() {
  int q;
  scanf("%d", &q);
  while(q--) {
    int t, w;
    long long u, v;
    scanf("%d%I64d%I64d", &t, &u, &v);
    if(t == 1) {
      scanf("%d", &w);
      while(u != v) {
        if(u < v) {
          mp[v] += w;
          v >>= 1;
        }
        else {
          mp[u] += w;
          u >>= 1;
        }
      }
    }
    else {
      long long ans = 0;
      while(u != v) {
        if(u < v)
          swap(u, v);
        if(mp.count(u))
          ans += mp[u];
        u >>= 1;
      }
      printf("%I64d\n", ans);
    }
  }  
  return 0;
}