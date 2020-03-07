#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, S = 2048, mod = 1e9 + 7;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int dp[N], cnt[N];

int comb[S][S];

int C(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  assert(n < S);
  return comb[n][k];
}


int main() {
  for (int i = 0; i < S; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
    }
  }
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> fact;
  for (int i = 1; i <= k; ++i) {
    if (k % i) continue;
    fact.push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ++cnt[a];
  }
  for (int i = 1; i < N; ++i) {
    for (int j = i+i; j < N; j += i)
      cnt[i] += cnt[j];
  }
  long long ans = 0;
  for (int sz : fact) {
    int til = k / sz;
    for (int i = N-1; i >= sz; --i) {
      dp[i] = C(cnt[i], til);
      for (int j = i+i; j < N; j += i) {
        if (dp[j] == 0) continue;
        dp[i] -= dp[j];
        if (dp[i] < 0)
          dp[i] += mod;
      }
    }
    ans += dp[sz];
    ans %= mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
