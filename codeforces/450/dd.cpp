#include <bits/stdc++.h>

using namespace std;

const int N = 111, mod = 1e9 + 7;

int dp[N][N];

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  dp[0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (dp[i][j] == 0) continue;
      for (int k = i+1; k < N; ++k) {
        int add = k - i;
        int & now = dp[k][gcd(add, j)];
        now += dp[i][j];
        if (now >= mod) now -= mod;
      }
    }
  }
  for (int i = 1; i < N; ++i) {
    cout << i << " " << dp[i][1] << endl;
  }
  return 0;
}