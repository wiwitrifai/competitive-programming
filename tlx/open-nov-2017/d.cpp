#include <bits/stdc++.h>

using namespace std;


const int N = 2048;

int c[N];
int dp[N];
int n, m;

bool can(long long ans) {
  int cur = m+1;
  for (int i = 0; i < n; i++) {
    dp[i] = i;
    for (int j = 0; j < i; j++) {
      long long d = llabs(c[j] - c[i]);
      int k = i-j;
      long long mi = (d + k - 1) / k;
      if (mi <= ans) {
        dp[i] = min(dp[i], dp[j] + i-j-1);
      }
    }
    cur = min(cur, dp[i] + (n-1-i));
  }
  return cur <= m;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", c+i);
  long long l = 0, r = 2e9;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}