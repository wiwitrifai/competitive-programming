#include <bits/stdc++.h>

using namespace std;

const int N = 3030, mod = 1e9 + 7, LG = 14;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = b * r % mod;
  return r;
}

long long inv(long long v) {
  return powmod(v, mod - 2);
}


long long dp[N][N][2], up[N][N], sumup[N][N][2], sumdown[N][N][2];

long long cost[N][N];
long long prob[N][N][LG];
int ma[N][N], h[N];
int a[N], b[N];


int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i+1 < n; ++i) {
      scanf("%d %d", a+i, b+i);
    }
    memset(h, 0, sizeof h);
    for (int i = 0; i < m; ++i) {
      int y, v;
      scanf("%d %d", &y, &v);
      --y;
      h[y] = max(h[y] , v); 
    }
    vector<int> vh;
    vh.push_back(0);
    for (int i = 0; i < n; ++i)
      vh.push_back(h[i]);
    sort(vh.begin(), vh.end());
    vh.erase(unique(vh.begin(), vh.end()), vh.end());
    for (int i = 0; i < n; ++i)
      h[i] = lower_bound(vh.begin(), vh.end(), h[i]) - vh.begin();
    for (int i = 0; i < n; ++i) {
      ma[i][i] = h[i];
      for (int j = i+1; j < n; ++j) {
        ma[i][j] = max(ma[i][j-1], h[j]);
      }
    }
    for (int i = 0; i + 1 < n; ++i) {
      long long down = inv(b[i] - a[i] + 1);
      for (int j = 0; j < vh.size(); ++j) {
        int now = max(a[i]-1, vh[j]);
        now = min(now, b[i]);
        prob[i][j][0] = (now - a[i] + 1) * 1LL * down % mod;
        up[i+1][j] = (b[i] - now) * 1LL * down % mod;
        // cerr << " prob " << i << " " << j << " " << prob[i][j][0] << endl;
      }
    }
    for (int j = 0; j < vh.size(); ++j)
      up[0][j] = 1;
    for (int k = 0; k + 1 < LG; ++k) {
      for (int i = 0; i + (1 << (k+1)) <= n; ++i) {
        for (int j = 0; j < vh.size(); ++j) {
          prob[i][j][k+1] = prob[i][j][k] * 1LL * prob[i+(1<<k)][j][k] % mod;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        int v = ma[i][j];
        int now = i;
        long long & res = cost[i][j];
        res = 1;
        for (int k = LG-1; k >= 0; --k) {
          if (now + (1 << k) <= j) {
            // cerr << " mul " << now << " " << v << " " << k << endl;
            res = (1LL * res * prob[now][v][k]) % mod;
            now += 1 << k;
          }
        }
        // cerr << " cost " << i << " " << j << " " << v << " = " << res << endl;
        assert(now == j);
      }
    }
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < vh.size(); ++j) {
        for (int s = 0; s < 2; ++s)
          sumdown[i-1][j][s] = ((j ? sumdown[i-1][j-1][s] : 0) + dp[i-1][j][s]) % mod;
      }
      sumup[i-1][vh.size()][0] = 0;
      sumup[i-1][vh.size()][1] = 0;
      for (int j = (int)vh.size() - 1; j >= 0; --j) {
        for (int s = 0; s < 2; ++s) {
          long long cur = dp[i-1][j][s] * 1LL * up[i-1][j] % mod;
          sumup[i-1][j][s] = ((j+1 < vh.size() ? sumup[i-1][j+1][s] : 0) + cur) % mod;
        }
      }
      for (int j = 0; j < i; ++j) {
        int v = ma[j][i-1];
        long long p = up[j][v];
        for (int s = 0; s < 2; ++s) {
          int snow = s | (v == 0);
          long long now = p * sumdown[j][v][s] + sumup[j][v+1][s];
          // cerr << j << " " << s << endl;
          // cerr << " " << p << " " << sumdown[j][v][s] << " " << sumup[j][v+1][s] << endl;;
          now %= mod;
          dp[i][v][snow] = (dp[i][v][snow] + now * cost[j][i-1]) % mod;
          // cerr << " " << " " << i << " " << v << " " << snow << " += " << now * cost[j][i-1] << " = " << dp[i][v][snow] << endl;
        }
      }
    }
    int ans = 0;
    for (int j = 0; j < vh.size(); ++j)
      ans = (ans + dp[n][j][1]) % mod;
    printf("Case #%d: %d\n", tc, ans);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}