#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long inf = 1e17;
int n, k;
int a[N];
long long dp[N][8];

int main() {
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);
  scanf("%d%d", &n, &k);
  k--;
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  if(k == 0) {
    long long ans = inf;
    for(int i = 0; i<n; i++) {
      long long now = 0;
      for(int j = 0; j<n; j++)
        now += 1LL*a[(i+j) % n] * j;
      ans = min(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
  }
  reverse(a, a+n);
  long long ans = inf;
  for(int st = 0; st < n; st++) {
    long long sum = 0, now = 0;
    for(int i = st; i<n; i++) {
      dp[i][0] = now;
      sum += a[i];
      now += sum;
      for(int j = 1; j<k; j++) {
        dp[i][j] = inf;
        long long add = 0;
        for(int d = i-1; d >= st; d--) {
          dp[i][j] = min(dp[i][j], dp[d][j-1]+add);
          add += 1LL*a[d]*(i-d);
        }
      }
    }
    sum = 0;
    now = 0;
    for(int i = st-1; i>=0; i--) {
      sum += a[i]*now;
      now++;
    }
    for(int i = n-1; i>=st; i--) {
      ans = min(ans, sum + dp[i][k-1]);
      sum += a[i]*now;
      now++;
    }
  }
  printf("%lld\n", ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}