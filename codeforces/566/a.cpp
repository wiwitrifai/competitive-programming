#include <bits/stdc++.h>

using namespace std;

const int N = 100;

long long dp[N];

int main() {
  dp[0] = 1;
  for (int i = 2; i < N; ++i) {
    dp[i] = 2 * dp[i-2];
  }
  int n;
  scanf("%d", &n);
  printf("%lld\n", dp[n]);
  return 0;
}
