#include <bits/stdc++.h>

using namespace std;


char testcase[50];
const int N = 1e6 + 5;
int n, a[N];
long long b[N], d[N];
int cnt[100];
long long dp[N];

int main() {
  scanf("%s", testcase);
  scanf("%d", &n);
  long long sum = 0;
  int now = 0;
  int ma = 0;
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    sum -= x;
    ma = max(ma, x);
    a[x]++;
    int ctz = __builtin_ctz(x);
    b[x>>ctz] += 1LL<<ctz;
    int off = 32-__builtin_clz(x);
    cnt[off]++;
    now += 1LL<<off;
    // cerr << i << " " << x << " " << ctz << " " << off << endl;
  }
  // cerr << now << " " << ma << " " << b[1] << endl;
  dp[1] = now - b[1];
  d[1] = a[1];
  long long ans = dp[1] + sum;
  cerr << ans << endl;
  cerr << 1 << " " << dp[1] << " " << d[1] << " " << dp[1] + sum << endl;

  for(int i = 2; i<=ma; i++) {
    d[i] = d[i-1] + a[i];
    if(i & 1) {
      dp[i] = - b[i] + dp[i^1] + b[i^1] - a[i^1];
    }
    else {
      int ctz = __builtin_ctz(i>>1);
      b[i] = (b[i>>1] - a[i>>1]) >> 1;
      dp[i] = (dp[i>>1] - d[i>>1])/2 + d[i>>1];
    }
    cerr << i << " " << dp[i] << " " << d[i] << " " << dp[i]*i + sum << endl;
    ans = min(ans, dp[i]*i + sum);
  }
  cout << ans << endl;
  return 0;
}