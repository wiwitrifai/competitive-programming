#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector< int > dv[N];
int dp[N], pre[N], li[N], ccur;
int dp2[N], pre2[N], li2[N], cnt2[N];
int print(int val, int cur, int lin) {
  int cnt = dp[val];
  while(lin--) {
    cur += pre[val];
    for(int i = 1; i<=pre[val]; i++)
      printf("%d ", cur - i);
    ccur -= pre[val];
    cnt -= pre[val];
    val /= pre[val];
  }
}

int main() {
  for(int i = 1; i<N; i++) {
    for(int j = i; j<N; j+= i)
      dv[j].push_back(i);
  }
  dp[1] = 1;
  pre[1] = 1;
  li[1] = 1;
  for(int i = 2; i<N; i++) {
    dp[i] = i;
    pre[i] = i;
    li[i] = 1;
    for(int j : dv[i]) {
      int a = i/j;
      if(dp[i] > dp[a] + j || (dp[i] == dp[a] + j && li[i] > li[a] + 1)) {
        dp[i] = dp[a] + j;
        pre[i] = j;
        li[i] = li[a] + 1;
      }
    }
  }
  // int ma = 0;
  for(int i = 1; i<N; i++) {
    dp2[i] = dp[i];
    pre2[i] = i;
    li2[i] = li[i];
    cnt2[i] = 1;
    for(int j = 1; j*j <= i; j++) {
      int lin = max(li2[j], li2[i-j]);
      int now = dp2[j] + (lin - li2[j]) * cnt2[j] + dp2[i-j] + (lin - li2[i-j]) * cnt2[i-j];
      if(dp2[i] > now) {
        dp2[i] = now;
        pre2[i] = j;
        li2[i] = lin;
        cnt2[i] = cnt2[j] + cnt2[i-j];
      }
    }
    // if(cnt2[i] >= 3 && i < 10000)
    //   cout << i << endl;
    // ma = max(ma, dp2[i]);
  }
  // cerr << ma << endl;
  int t;
  scanf("%d", &t);
  while(t--) {
    int k;
    scanf("%d", &k);
    // cnt = dp2[k];
    printf("%d\n", dp2[k]);
    ccur = dp2[k];
    int lin = li2[k];
    while(k) {
      int prev = pre2[k];
      // cout << " (" << dp2[k] << " = " << prev << ", "<<dp2[prev] << " " << li2[prev] << " " << cnt2[prev] << " | " << k-prev << ", "<<dp2[k-prev] << " " << li2[k-prev] << " " << cnt2[k-prev] << ") ";
      print(prev, ccur - dp[prev] - (lin-li[prev]) + 1, lin);
      k -= prev;
    }
    printf("\n");
  }
  return 0;
}