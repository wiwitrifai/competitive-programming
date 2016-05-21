#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long dp[1<<16];

int get(int x) {
  int bs = 1;
  int now = 0;
  while(x) {
    int k = x % 10;
    x /= 10;
    now ^= k;
    bs |= 1<<now;
  }
  return dp[bs];
}

int main() {
  for(int i = (1<<16) - 1; i>=0; i--) {
    dp[i] = 0;
    set< int > st;
    for(int j = 0; j<16; j++) if(i & (1<<j))
      for(int k = j+1; k<16; k++) if(i & (1<<k)) {
        if(!st.count(j ^ k)) {
          dp[i] = (dp[i] + (j^k)) % mod;
          st.insert(j^k);
        }
      }
  }
  int t;
  // for(int i = 1; i<=1000000; i++)
  //   cout << get(i) << endl;
  scanf("%d", &t);
  while(t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    long long ans = 0;
    for(int i = l; i<=r; i++)
      ans = (ans + get(i)) % mod;
    printf("%lld\n", ans);
  }

  return 0;
}