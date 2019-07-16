#include <bits/stdc++.h>

using namespace std;

const int N = 16;

int from[1 << N];
int dp[N+1][1 << N];

string cur, now;

void upd(int & var, int val) {
  if (var < val)
    var = val;
}

void process(string a, string b) {
  now = b;
  int n = a.size(), m = b.size();
  int nmask = 1 << n, mmask = 1 << m;
  memset(dp, -1, sizeof dp);
  for (int mask = 0; mask < nmask; ++mask) {
    if (from[mask] <= -1) continue;
    cur.clear();
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        cur.push_back(a[i]);
      }
    }
    int bmask = 0;
    cur.push_back('\0');
    int len = cur.size();
    for (int i = 0, j = 0; i < len; ++i) {
      for (int k = j; k < m; ++k) {
        if (now[k] > cur[i]) {
          int cmask = bmask | (1 << k);
          upd(dp[k+1][cmask], from[mask] + __builtin_popcount(cmask));
        }
      }
      while (j < now.size() && now[j] != cur[i]) ++j;
      if (j == now.size())
        break;
      bmask |= 1 << j;
      ++j;
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < mmask; ++j) {
      if (dp[i][j] == -1) continue;
      upd(dp[i+1][j], dp[i][j]);
      upd(dp[i+1][j|(1<<i)], dp[i][j]+1);
    }
  }
  for (int i = 0; i < mmask; ++i)
    from[i] = dp[m][i];
  from[0] = -1;
}

char buf[N+N];
string s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    s[i] = buf;
  }
  from[0] = -1;
  int nmask = 1 << s[0].size();
  for (int i = 1; i < nmask; ++i) {
    from[i] = __builtin_popcount(i);
  }
  for (int i = 0; i + 1 < n; ++i) {
    process(s[i], s[i+1]);
  }
  int ans = -1;
  nmask = 1 << s[n-1].size();
  for (int i = 0; i < nmask; ++i)
    ans = max(ans, from[i]);
  printf("%d\n", ans);
  return 0;
}