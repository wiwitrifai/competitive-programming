#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 5, mod = 1e9 + 7;

long long dp[30][44][44];

string b, s[30]; 
bool vis[30];

void add(long long &le, long long ri) {
  le += ri;
  if (le >= mod)
    le -= mod;
}

void solve(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  for (int i = 0; i < s[x].size(); i++)
    if ('A' <= s[x][i] && s[x][i] <= 'Z')
      solve(s[x][i] - 'A');
  int n = b.size(), m = s[x].size(); 
  for (int i = 0; i < n; i++) {
    for (int j = i; j <= n; j++)
      dp[x][i][j] = 0;
    dp[x][i][i] = 1;
  }
  for (char c : s[x]) {
    if ('A' <= c && c <= 'Z') {
      c -= 'A';
      for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= i; j--) {
          if (dp[x][i][j] == 0) continue;
          for (int k = j+1; k <= n; k++)
            add(dp[x][i][k], 1LL * dp[x][i][j] * dp[c][j][k] % mod); 
        }
      }
    }
    else {
      for (int j = n-1; j >= 0; j--) if (b[j] == c) {
        for (int i = 0; i <= j; i++) {
          add(dp[x][i][j+1], dp[x][i][j]);
        }
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    cin >> b;
    cin >> s[26];
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      int d = c-'A';
      cin >> s[d];
    }
    memset(vis, 0, sizeof vis);
    solve(26);
    printf("%lld\n", dp[26][0][b.size()]);
  }
  return 0;
}