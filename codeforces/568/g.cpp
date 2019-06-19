#include <bits/stdc++.h>

using namespace std;

const int N = 51, T = 2502, mod = 1e9 + 7;

int dp[N][N][T], dpc[N][T];

vector<int> songs[4];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

long long fac[N * 3];
int calc[N][N][N];
int loc[N][N][N][3];

int main() {
  fac[0] = 1;
  for (int i = 1; i < N * 3; ++i) {
    fac[i] = 1LL *fac[i-1] * i % mod;
  }
  loc[1][0][0][0] = 1;
  loc[0][1][0][1] = 1;
  loc[0][0][1][2] = 1;
  for (int a = 0; a < N; ++a) {
    for (int b = 0; b < N; ++b) {
      for (int c = 0; c < N; ++c) {
        int & cur = calc[a][b][c];
        cur = 0;
        for (int last = 0; last < 3; ++last) {
          int now = loc[a][b][c][last];
          if (now == 0) continue;
          add(cur, now);
          if (last != 0 && a + 1 < N)
            add(loc[a+1][b][c][0], now);
          if (last != 1 && b + 1 < N)
            add(loc[a][b+1][c][1], now);
          if (last != 2 && c + 1 < N)
            add(loc[a][b][c+1][2], now);
        }
        cur = 1LL * cur * fac[a] % mod;
        cur = 1LL * cur * fac[b] % mod;
        cur = 1LL * cur * fac[c] % mod;
      }
    }
  }
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; ++i) {
    int w, g;
    scanf("%d %d", &w, &g);
    --g;
    songs[g].emplace_back(w);
  }
  int cnta = 0;
  dp[0][0][0] = 1;
  for (int w : songs[0]) {
    for (int j = cnta; j >= 0; --j) {
      int til = t - w;
      for (int k = 0; k <= til; ++k) {
        int now = dp[j][0][k];
        if (now == 0) continue;
        add(dp[j+1][0][k+w], now);
      }
    }
    ++cnta;
  }
  for (int a = 0; a <= cnta; ++a) {
    int cntb = 0;
    for (int w : songs[1]) {
      for (int j = cntb; j >= 0; --j) {
        int til = t - w;
        for (int k = 0; k <= til; ++k) {
          int now = dp[a][j][k];
          if (now == 0) continue;
          add(dp[a][j+1][k+w], now);
        }
      }
      ++cntb;
    }
  }
  int cntb = songs[1].size();
  dpc[0][0] = 1;
  int cntc = 0;
  for (int w : songs[2]) {
    for (int j = cntc; j >= 0; --j) {
      int til = t - w;
      for (int k = 0; k <= til; ++k) {
        int now = dpc[j][k];
        if (now == 0) continue;
        add(dpc[j+1][k+w], now);
      }
    }
    ++cntc;
  }
  long long ans = 0;
  for (int a = 0; a <= cnta; ++a) {
    for (int b = 0; b <= cntb; ++b) {
      for (int tab = 0; tab <= t; ++tab) {
        int dab = dp[a][b][tab];
        int sisa = t - tab;
        if (dab == 0) continue;
        for (int c = 0; c <= cntc; ++c) {
          int dc = dpc[c][sisa];
          if (dc == 0) continue;
          long long cur = 1LL * dab * dc % mod;
          ans = (ans + 1LL * calc[a][b][c] * cur) % mod;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
