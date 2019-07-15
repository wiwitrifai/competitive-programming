#include <bits/stdc++.h>

using namespace std;

const int N = 111, mod = 998244353;

char s[N];
int dig[N], n;

int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}

map<pair<int, int>, int> dp[2][2][10][10];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}
int to1[10], to2[10];

long long solve(int x, int y) {
  memset(dp, 0, sizeof dp);
  int c = 0, b = 1;
  memset(to1, 0, sizeof to1);
  memset(to2, 0, sizeof to2);
  for (int i = 1; i * y < 10; ++i) {
    to1[i * x] = 1 << (i-1);
    to2[i * y] = 1 << (i-1);
  }
  for (int lebih = 0; lebih < 2; ++lebih) {
    for (int l = 0; l < 10; ++l) {
      for (int r = 0; r < 10; ++r) {
        dp[c][lebih][l][r].clear();
      }
    }
  }
  dp[c][0][0][0][{0, 0}] = 1;
  for (int i = 0; i < n; ++i) {
    swap(c, b);
    for (int lebih = 0; lebih < 2; ++lebih) {
      for (int l = 0; l < 10; ++l) {
        for (int r = 0; r < 10; ++r) {
          dp[c][lebih][l][r].clear();
        }
      }
    }
    for (int lebih = 0; lebih < 2; ++lebih) {
      for (int l = 0; l < 10; ++l) {
        for (int r = 0; r < 10; ++r) {
          for (auto it : dp[b][lebih][l][r]) {
            int now = it.second;
            int maska = it.first.first, maskb = it.first.second;
            if (now == 0) continue;
            for (int k = 0; k < 10; ++k) {
              int ll = l + x * k, rr = r + y * k;
              int dl = ll % 10, dr = rr % 10;
              ll /= 10; rr /= 10;
              int more = 0;
              if (dr > dig[i])
                more = 1;
              else if (dr == dig[i])
                more = lebih;
              int mmaska = maska, mmaskb = maskb;
              if (mmaska != -1) {
                mmaska |= to1[dl];
                mmaskb |= to2[dr];
                if (mmaska & mmaskb)
                  mmaska = mmaskb = -1;
              }
              add(dp[c][more][ll][rr][{mmaska, mmaskb}], now);
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (auto it : dp[c][0][0][0]) {
    auto mask = it.first;
    if (mask.first & mask.second)
      add(ans, it.second);
  }
  return ans;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i)
    dig[n-1-i] = s[i]-'0';
  dig[n] = 0;
  long long ans = 0;
  for (int x = 1; x <= 9; ++x) {
    for (int y = x; y <= 9; ++y) {
      if (gcd(x, y) != 1) continue;
      long long res = solve(x, y);
      ans = (ans + res) % mod;
      if (x != y)
        ans = (ans + res) % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
