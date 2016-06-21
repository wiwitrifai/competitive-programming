#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5, M = 55, Z = 1<<11;
vector<int > prime;
bitset< M > bs;

int n;
int dp[2][Z];
pair< int, int > val[N];
int main() {
  bs.set();
  bs[0] = bs[1] = 0;
  for(int i = 2; i<M; i++) if(bs[i]) {
    prime.push_back(i);
    for(int j = i * i; j<M; j += i)
      bs[j] = 0;
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(dp, 0, sizeof dp);
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
      int x;
      scanf("%d", &x);
      int cur = x, mask = 0;
      for(int j = 0; j<11; j++)
        while((cur % prime[j]) == 0) {
          mask |= 1<<j;
          cur /= prime[j];
        }
      val[i] = make_pair(cur, mask);
    }
    sort(val, val+n);
    // for(int i = 0; i<n; i++)
    //   cerr << val[i].first << " " << val[i].second << endl;
    int cur = 0;
    while(cur < n && val[cur].first == 1) {
      int mask = val[cur].second;
      for(int i = mask; i<Z; i = (i+1) | mask)
        dp[1][i] = max(dp[1][i], dp[1][i^mask] + 1);
      cur++;
    }
    int last = 1;
    for(int i = cur; i<n; i++) {
      if(last != val[i].first) {
        memcpy(dp[0], dp[1], sizeof dp[0]);
        last = val[i].first;
      }
      int mask = val[i].second;
      for(int j = mask; j<Z; j = (j + 1) | mask) {
        dp[1][j] = max(dp[0][j ^ mask] + 1, dp[1][j]);
      }
    }
    int ans = 0;
    for(int i = 0; i<Z; i++)
      ans = max(ans, dp[1][i]);
    printf("%d\n", ans);
  }
  return 0;
}