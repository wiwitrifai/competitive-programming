#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 5;

const int N = sqrt(M);
bitset< N > bs;
vector< int > prim, pan_prim;
int a[10];

bool isPrim(int n) {
  if(n < N)
    return bs[n];
  bool ret = true;
  for(auto p : prim)
    if((n % p) == 0) {
      ret = false;
      break;
    }
  return ret;
}

int main() {
  bs.set();
  for(int i = 2; i<N; i++) if(bs[i]) {
    for(int j = i * i; j < N; j+= i)
      bs[j] = 0;
    prim.push_back(i);
  }
  for(int i = 4; i<= 8; i++) {
    for(int j = 1; j<=i; j++)
      a[j-1] = j;
    do {
      int now = 0;
      for(int j = 0; j<i; j++) {
        now = now * 10 + a[j];
      }
      if(isPrim(now))
        pan_prim.push_back(now);
    } while(next_permutation(a, a+i));
  }
  sort(pan_prim.begin(), pan_prim.end());
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int ans = upper_bound(pan_prim.begin(), pan_prim.end(), n) - pan_prim.begin() - 1;
    if(ans >= 0)
      ans = pan_prim[ans];
    printf("%d\n", ans);
  }
  return 0;
}