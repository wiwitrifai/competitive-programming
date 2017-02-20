#include <bits/stdc++.h>

using namespace std;

long long dp[55];

long long get(long long n, int k, long long l, long long r) {
  if (l > r) return 0;
  if (k == 0)
    return n;
  if (l == 1 && r == dp[k])
    return n;
  long long ans = 0;
  if (l <= dp[k-1]+1 && dp[k-1]+1 <= r)
    ans += n & 1;
  if (l < dp[k-1] + 1)
    ans += get(n/2, k-1, l, min(dp[k-1], r));
  if (r > dp[k-1] + 1)
    ans += get(n/2, k-1, max(l-dp[k-1]-1,1LL), r-dp[k-1]-1); 
  return ans;
}

int main() {
  dp[0] = 1;
  for (int i = 1; i < 55; i++)
    dp[i] = dp[i-1] + dp[i-1] + 1;
  long long n, l, r;
  cin >> n >> l  >> r;
  int k = 0;
  while ((1LL << k) <= n) k++;
  cout << get(n, k-1, l, r) << endl;
  return 0;
}