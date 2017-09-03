#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
char a[N], b[N];
bool up[N], down[N];

long long get(char x[N]) {
  int n = strlen(x);
  if(n == 1)
    return x[0]-'0'+1;
  up[0] = true, down[0] = true;
  for(int i = 1; i<n; i++) {
    up[i] = down[i-1] && x[i-1] < x[i];
    down[i] = up[i-1] && x[i-1] > x[i];
  }
  long long ret = 0;
  if(up[n-1] || down[n-1])
    ret++;
  long long dp[2][10], tmp[10];
  for(int i = 0; i<10; i++)
    dp[0][i] = dp[1][i] = 1;
  for(int i = n-1; i>0; i--) {
    if(up[i-1]) {
      for(int j = 0; j<min(x[i], x[i-1])-'0'; j++)
        ret = (ret + dp[0][j]) % mod;
    }
    if(down[i-1]) {
      for(int j = x[i-1]-'0'+1; j<x[i]-'0'; j++)
        ret = (ret + dp[1][j]) % mod;
    }
    if(i < n-1)
      for(int j = 1; j<10; j++)
        ret = (ret + dp[0][j] + dp[1][j]) % mod;
      else 
        ret = (ret + 10) % mod;
    long long sum = 0;
    for(int j = 0; j<10; j++) {
      tmp[j] = sum;
      sum = (sum + dp[0][j]) % mod;
    }
    sum = 0;
    for(int j = 9; j>=0; j--) {
      dp[0][j] = sum;
      sum = (sum + dp[1][j]) % mod;
      dp[1][j] = tmp[j];
    }
  }
  for(int i = 1; i<x[0]-'0'; i++)
    ret = (ret + dp[0][i] + dp[1][i]) % mod;
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s%s", a, b);
    int off = 0;
    while(b[off] == '0' && b[off+1] != '\0')
      off++;
    long long ans = get(b);
    int n = strlen(a);
    a[n-1]--;
    for(int i = n-1; i>0; i--) {
      if(a[i] < '0') {
        a[i-1]--;
        a[i] = '9';
      }
      else
        break;
    }
    off = 0;
    while(a[off] == '0' && a[off+1])
      off++;
    ans -= get(a+off);
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}