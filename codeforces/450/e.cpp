#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6, LG = 15, inf = 1e9 + 7;

char s[N];

bool ok[N];
int c[N];
int best[N];
int dp[N][LG];

int main() {
  int n, m;
  scanf("%d %s %d", &n, s, &m);
  {
    int salah = 0, tanya = 0;
    for (int i = 0; i < m; ++i) {
      if (s[i] == '?')
        tanya++;
      else if (s[i] == 'a')
        salah += i & 1;
      else
        salah += (i & 1) == 0;
    }
    for (int i = 0; i + m <= n; i += 2) {
      if (salah == 0) {
        ok[i] = 1;
        c[i] = tanya;
      }
      salah -= (s[i] == 'b') + (s[i+1] == 'a');
      tanya -= (s[i] == '?') + (s[i+1] == '?');
      if (m & 1)
        salah += (s[i+m] == 'a') + (s[i+m+1] == 'b');
      else
        salah += (s[i+m] == 'b') + (s[i+m+1] == 'a');
      tanya += (s[i+m] == '?') + (s[i+m+1] == '?');
    }
  }
  {
    int salah = 0, tanya = 0;
    for (int i = 1; i <= m; ++i) {
      if (s[i] == '?')
        tanya++;
      else if (s[i] == 'a')
        salah += (i & 1) == 0;
      else
        salah += i & 1;
    }
    for (int i = 1; i + m <= n; i += 2) {
      if (salah == 0) {
        ok[i] = 1;
        c[i] = tanya;
      }
      salah -= (s[i] == 'b') + (s[i+1] == 'a');
      tanya -= (s[i] == '?') + (s[i+1] == '?');
      if (m & 1)
        salah += (s[i+m] == 'a') + (s[i+m+1] == 'b');
      else
        salah += (s[i+m] == 'b') + (s[i+m+1] == 'a');
      tanya += (s[i+m] == '?') + (s[i+m+1] == '?');
    }
  }
  // for (int i = 0; i < n; ++i)
  //   if (ok[i])
  //     cerr << i << " " << c[i] << endl;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < LG; ++j)
      dp[i][j] = inf;
  for (int i = n; i >= 0; --i) {
    best[i] = best[i+1];
    if (ok[i])
      best[i] = max(best[i], best[i+m] + 1);
    // cerr << i << " ? " << best[i] << endl;
    for (int j = 0; j < LG; ++j) {
      int now = best[i] - j;
      if (now == 0)
        dp[i][j] = 0;
      else {
        int k = best[i+1] - now;
        if (k >= 0 && k < LG)
          dp[i][j] = dp[i+1][k];
        else
          dp[i][j] = inf;
      }
    }
    if (ok[i]) {
      int to = min(LG, best[i]);
      for (int j = 0; j < to; ++j) {
        int now = best[i] - j - 1;
        int k = best[i+m] - now;
        if (k >= 0 && k < LG) {
          dp[i][j] = min(dp[i][j], dp[i+m][k] + c[i]); 
          // cerr << i << " " << now + 1 << " " << i+m << " " << k << " " << dp[i+m][k] + c[i] << endl; 
        }
      }
    }
    // for (int j = 0; j < LG; ++j)
    //   cerr << i << " " << j << " " << dp[i][j] << endl;
  }
  // cerr << best[0] << endl;
  printf("%d\n", dp[0][0]);
  return 0;
}