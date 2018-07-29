#include <bits/stdc++.h>

using namespace std;

const int N = 105, M = 1001, S = 5005;

char g[N][N];
char w[M][S];
int len[M];

int row[N][N][N];
int col[N][N][N];
long long dp[2][N][N][N];
long long cnt[N][N];

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

void solve(int tc) {
  int ansp = 0, ansq = 1;
  int r, c, n;
  scanf("%d %d %d", &r, &c, &n);
  for (int i = 0; i < r; ++i)
    scanf("%s", g[i]);
  for (int i = 0; i < n; ++i)
    scanf("%s", w[i]), len[i] = strlen(w[i]);
  memset(col, 0, sizeof col);
  memset(row, 0, sizeof row);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      for (int k = 0; k < n; ++k) {
        if (i + len[k] <= r) {
          bool ok = 1;
          for (int l = 0; l < len[k]; ++l) {
            if (w[k][l] != g[i+l][j]) {
              ok = 0;
              break;
            }
          }
          if (ok)
            col[j][i][i+len[k]-1] += len[k];
          ok = 1;
          for (int l = 0; l < len[k]; ++l) {
            if (w[k][len[k]-1-l] != g[i+l][j]) {
              ok = 0;
              break;
            }
          }
          if (ok)
            col[j][i][i+len[k]-1] += len[k];
        }
        if (j + len[k] <= c && len[k] > 1) {
          bool ok = 1;
          for (int l = 0; l < len[k]; ++l) {
            if (w[k][l] != g[i][j+l]) {
              ok = 0;
              break;
            }
          }
          if (ok)
            row[i][j][j+len[k]-1] += len[k];
          ok = 1;
          for (int l = 0; l < len[k]; ++l) {
            if (w[k][len[k]-1-l] != g[i][j+l]) {
              ok = 0;
              break;
            }
          }
          if (ok)
            row[i][j][j+len[k]-1] += len[k];
        }
      }
    }
  }
  memset(dp, 0, sizeof dp);
  int id = 0, pre = 1;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      long long cur = 0;
      for (int a = i; a >= 0; --a) {
        cur += col[j][a][i];
        long long now = cur;
        for (int b = j; b >= 0; --b) {
          now += row[i][b][j];
          res = now + dp[pre][j][a][b];
          if (j > 0) {
            res += dp[id][j-1][a][b] - dp[pre][j-1][a][b];
          }
          dp[id][j][a][b] = res;
          long long curp = res, curq = (i-a+1) + (j-b+1);
          if (ansp * curq < curp * ansq)
            ansp = curp, ansq = curq;
        }
      }
    }
  }
  long long gc = gcd(ansp, ansq);
  ansp /= gc;
  ansq /= gc;
  printf("Case #%d: %lld/%lld\n", tc, ansp, ansq);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}