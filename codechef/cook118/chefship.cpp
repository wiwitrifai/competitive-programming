#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5, H = 2;

vector<int> prime = {37, 29};
vector<int> mod = {int(1e9 + 7), int(1e9 + 9)};

char s[N];

long long powmod(long long b, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}

long long pw[H][N];
long long hashs[H][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < H; ++i) {
    pw[i][0] = 1;
    long long p = prime[i], m = mod[i];
    for (int j = 1; j < N; ++j) {
      pw[i][j] = pw[i][j-1] * p % m;
    }
  }
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < H; ++i) {
      int m = mod[i];
      hashs[i][0] = 0;
      for (int j = 0; j < n; ++j) {
        hashs[i][j+1] = (hashs[i][j] + pw[i][j] * (s[j] - 'a' + 1)) % m;
      }
    }
    auto cek = [&](int l, int r, int x, int y) {
      for (int i = 0; i < H; ++i) {
        long long ret0 = (hashs[i][r] - hashs[i][l]) * pw[i][x-l] % mod[i];
        if (ret0 < 0)
          ret0 += mod[i];
        long long ret1 = (hashs[i][y] - hashs[i][x]);
        if (ret1 < 0)
          ret1 += mod[i];
        if (ret0 != ret1)
          return false;
      }
      return true;
    };
    long long half = n / 2;
    int ans = 0;
    for (int a = 1; a < half; ++a) {
      int b = half - a;
      if (!cek(0, a, a, a+a))
        continue;
      if (!cek(a+a, a+a+b, a+a+b, n))
        continue;
      ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
