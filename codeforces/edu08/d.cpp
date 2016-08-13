#include <bits/stdc++.h>

using namespace std;

const int N = 2016;
const int mod = 1e9 + 7;

long long powmod(long long b, long long p, long long mm) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mm;
    b = (b * b) % mm;
    p >>= 1;
  }
  return ret;
}

int n, m, d;
long long dp[N][N], mul[N];


long long get(char s[N]) {
  long long ret = 0;
  int state = 1;
  long long rem = 0;
  for (int i = 0; i<n; i++) {
    int now = s[i]-'0';
    if (state) {
      for (int j = 0; j < now; j++) {
        if (j == d)
          continue;
        rem = (rem + mul[n-i-1] * j) % m;
        ret = (ret + dp[i+1][(m - rem) % m]) % mod;
        rem = (rem - mul[n-i-1] * j) % m;
        if (rem < 0)
          rem += m;
      }
      if(now == d)
        break;
      rem = (rem + mul[n-i-1] * now) % m;
    }
    else {
      if (now > d) {
        rem = (rem + mul[n-i-1] * d) % m;
        ret = (ret + dp[i+1][(m - rem) % m]) % mod;
      }
      if (now != d)
        break;
    }
    state = !state;
  }
  return ret;
}

char a[N], b[N];

int main() {
  scanf("%d %d", &m, &d);
  scanf("%s %s", a, b);
  mul[0] = 1;
  for (int i = 1; i<N; i++)
    mul[i] = (mul[i-1] * 10) % m; 
  n = strlen(a);
  int state = n & 1;
  memset(dp, 0, sizeof dp);
  dp[n][0] = 1;

  for (int i = n-1; i >= 0; i--) {
    if(state) {
      for (int j = 0; j < m; j++) if (dp[i+1][j]) {
        for (int k = 0; k <= 9; k++) {
          if (k == d)
            continue;
          dp[i][(j + mul[n-i-1]*k) % m] = (dp[i][(j + mul[n-i-1]*k) % m] + dp[i+1][j]) % mod;
        }
      }
    }
    else {
      for (int j = 0; j < m; j++) {
        dp[i][(j + mul[n-i-1] *d) % m] = (dp[i][(j + mul[n-i-1] *d) % m] + dp[i+1][j]) % mod;
      }
    }
    state = !state;
  }
  a[n-1]--;
  int now = n-1;
  while (a[now] < '0') {
    a[now] = '9';
    a[now-1]--;
    now--;
  }
  long long ans = get(b) - get(a);
  ans %= mod;
  if(ans < 0)
    ans += mod;
  cout << ans << endl;
  return 0;
}