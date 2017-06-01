#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int prime[N], np;
long long dp[N];

int main() {
  prime[0] = 2;
  np = 1;
  for(int i = 3; i<N; i+= 2) {
    bool ok = true;
    for(int j = 0; j<np; j++)
      if((i % prime[j]) == 0)
        ok = false;
    if(ok)
      prime[np++] = i;
  }
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for(int i = 0; i<np; i++) {
    for(int j = prime[i]; j<N; j++) {
        dp[j] += dp[j-prime[i]];
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp[n]);
  }
  return 0;
}