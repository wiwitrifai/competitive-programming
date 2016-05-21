#include <bits/stdc++.h>

using namespace std;

const int B = 15, NB = 1<<B;
const int mod = 1e9 + 7;

long long val[NB];
int to[NB][B+1];
int dp[11][NB];
long long cnt[10];

long long get(int x) {
  long long n = 1;
  int k = -1;
  while(n <= x) {
    n *= 10;
    k++;
  }
  long long ret = 0;
  int now = 0, cur = 0;
  while(k >= 0) {
    n /= 10;
    int a = x / n;
    x %= n;
    for(int i = 0; i<a; i++) {
      for(int j = 0; j<NB; j++) {
        int tmp = (now) ? cur|(1<<(now-1)) : cur;
        ret = (ret + val[tmp|to[j][now]] * dp[k][j]) % mod;
      }
      now ^= i;
      now ^= (i+1);
    }
    if(now)
      cur |= 1<<(now-1);
    k--;
  }
  return ret;
}

int main() {
  for(int i = 0; i<NB; i++) {
    val[i] = 0;
    set< int > st;
    for(int j = 0; j<B; j++) {
      if(i & (1<<j)) {
        if(!st.count(j+1)) {
          val[i] = (val[i] + j+1) % mod;
          st.insert(j+1);
        }
        for(int k = j+1; k<B; k++) if(i & (1<<k)) {
          if(!st.count((j+1)^(k+1))) {
            val[i] = (val[i] + ((j+1) ^ (k+1))) % mod;
            st.insert((j+1)^(k+1));
          }
        }
      }
    }
  }
  for(int i = 1; i<=B; i++)
    to[0][i] = 1<<(i-1);
  for(int i = 1; i < NB; i++) {
    for(int j = 0; j<=B; j++) {
      int cur = 0;
      for(int k = 0; k<B; k++)
        if((i & (1<<k))) {
          int shift = ((j ^ (k+1))-1);
          if(shift >= 0)
            cur ^= (1<<shift);
        }
      to[i][j] = cur;
    }
  }
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for(int i = 0; i<10; i++) {
    for(int k = 0; k<NB; k++)
      dp[i+1][k] = 0;
    for(int k = 0; k<NB; k++)
      for(int j = 0; j<10; j++) {
        int tmp = to[k][j] | (j ? 1<<(j-1) : 0);
        dp[i+1][tmp] += dp[i][k];
        dp[i+1][tmp] %= mod;
      }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    long long ans = get(r+1) - get(l);
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}