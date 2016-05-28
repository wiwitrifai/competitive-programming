#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;
long long dp[N];

int main() {
  dp[0] = 1;
  for(int i = 1; i<N; i++) {
    for(int j = i; j<N; j++)
      dp[j] = (dp[j] + dp[j-i]) % mod;
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp[n]-1);
  }

  return 0;
}