#include <bits/stdc++.h>

using namespace std;

const int N = 55, mod = 1e9 + 7;

int dp[2][N][N][N][N][2];

int x[N], y[N];

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n, s, e;
    scanf("%d %d %d", &n, &s, &e);
    vector<int> vx;
    vx.push_back(s);
    vx.push_back(e);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", x+i, y+i);
      swap(x[i], y[i]);
      vx.push_back(x[i]);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    e = lower_bound(vx.begin(), vx.end(), e) - vx.begin() + 1;
    s = lower_bound(vx.begin(), vx.end(), s) - vx.begin() + 1;
    vector<pair<int, int> > vp;
    int m = vx.size() + 1;
    assert(e > 0 && e < m);
    assert(s > 0 && s < m);
    for (int i = 0; i < n; ++i) {
      x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
      vp.emplace_back(y[i], x[i]);
      assert(x[i] >= 1 && x[i] < m);      
    }
    assert(m == n+2+1);
    sort(vp.begin(), vp.end());
    memset(dp, 0, sizeof dp);
    dp[0][0][m][0][m][0] = 1;
    int c = 0, b = 1;
    for (auto it : vp) {
      swap(c, b);
      for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
          for (int k = 0; k <= m; ++k) {
            for (int l = 0; l <= m; ++l) {
              for (int z = 0; z < 2; ++z) {
                dp[c][i][j][k][l][z] = 0;
              }
            }
          }
        }
      }
      int xx = it.second;
      for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
          for (int k = 0; k <= e; ++k) {
            for (int l = e; l <= m; ++l) {
              for (int z = 0; z < 2; ++z) {
                int cur = dp[b][i][j][k][l][z];
                if (cur == 0) continue;
                assert( k < e && e < l);
                { // atas
                  int zz = z;
                  if (j <= xx && xx <= s)
                    zz = 1;
                  if (i >= xx && xx >= s)
                    zz = 1;
                  add(dp[c][i][j][k][l][zz], cur);
                }
                { // kanan
                  int zz = z;
                  if (k >= xx)
                    zz = 1;
                  add(dp[c][i][min(j, xx)][k][l][zz], cur);
                }
                { // kiri
                  int zz = z;
                  if (l <= xx)
                    zz = 1;
                  add(dp[c][max(i, xx)][j][k][l][zz], cur);
                }
                { // bawah
                  int kk = k, ll = l;
                  if (xx <= e)
                    kk = max(xx, kk);
                  else
                    ll = min(xx, ll);
                  add(dp[c][i][j][kk][ll][z], cur);
                }
              }
            }
          }
        }
      }
    }
    int ans = 0;

    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= m; ++k) {
          for (int l = 0; l <= m; ++l) {
            add(ans, dp[c][i][j][k][l][1]);
          }
        }
      }
    }
    printf("Case #%d: %d\n", tc, ans);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}