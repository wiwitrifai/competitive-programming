#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

long long dp[N];


int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    dp[0] = 2;
    int n, k;
    scanf("%d%d", &n, &k);
    if(n == 0) {
      puts("1");
      continue;
    }
    if(k == 0) {
      puts("0");
      continue;
    }
    long long sum = dp[0];
    for(int i = 1; i<=n; i++) {
      dp[i] = sum;
      sum = (sum+dp[i]) % mod;
      if(i >= k)
        sum = (sum + (mod - dp[i-k])) % mod;
      assert(dp[i] >= 0);
    }
    printf("%lld\n", dp[n]);
  }
  return 0;
}