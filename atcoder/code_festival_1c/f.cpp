#include <bits/stdc++.h>

using namespace std;

const int N = 404, mod = 1e9 + 7;

bool can[N][N];
int dp[N][N], bef[N][N], com[N][N], sum[N][N];

int a[N], b[N];
bool ada[N];

inline void upd(int &le, int ri) {
  le += ri;
  if (le >= mod)
    le -= mod;
}

void update(int id, int x, int val) {
  for (; x; x -= x &-x)
    upd(sum[id][x], val);
}

int get(int id, int x) {
  if (id < 0) return 0;
  int ret = 0;
  for (; x < N; x += x&-x)
    upd(ret, sum[id][x]);
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      can[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    ada[a[i]] = 1;
    for (int j = 0; j < n; j++)
      if (ada[b[j]])
        can[i][j] = 0;
  }
  memset(ada, 0, sizeof ada);
  for (int j = 0; j < n; j++) {
    ada[b[j]] = 1;
    for (int i = 0; i < n; i++)
      if (ada[a[i]])
        can[i][j] = 0;
  }
  memset(ada, 0, sizeof ada);
  for (int i = n-1; i >= 0; i--) {
    int cnt = 0;
    for (int j = n-1; j >= 0; j--) {
      com[i][j] = cnt;
      cnt += ada[b[j]];
    }
    ada[a[i]] = 1;
  }
  int m = n/3;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (can[i][j])
        dp[i][j] = com[i][j];
  for (int k = 1; k < m; k++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        bef[i][j] = dp[i][j];
        dp[i][j] = 0;
      }
    memset(sum, 0, sizeof sum);
    for (int i = n-1; i >= 0; i--) {
      for (int j = n-1; j >= 0; j--) {
        if (can[i][j] && com[i][j] >= 3 * k) {
          // cerr << k << " " << i << " " << j << " " << get(com[i][j]-2, j+1) <<" * " << (com[i][j] - 2 - k) << endl;
          // cerr << k << " " << i << " " << j << " " << get(com[i][j]-3, j+1) <<" * " <<  endl;
          upd(dp[i][j], get(com[i][j]-2, j+1) * (com[i][j] - 3 * k) % mod);
          upd(dp[i][j], get(com[i][j]-3, j+1));
        }
        if (i+1 < n) {
          update(com[i+1][j], j, bef[i+1][j]);
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cerr << bef[i][j] << " ";
    //   }
    //   cerr << endl;
    // }
    // cerr << endl;
    // cerr << k << endl;
  }

    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cerr << dp[i][j] << " ";
    //   }
    //   cerr << endl;
    // }
    // cerr << endl;
  int ans = dp[0][0];
  cerr << ans << endl;
  for (int i = 1; i <= n; i++) {
    if ((i % 3) == 0) continue;
    ans = (1LL * ans * i) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%d\n", ans);
  return 0;
}