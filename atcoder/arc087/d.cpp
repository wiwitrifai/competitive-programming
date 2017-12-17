#include <bits/stdc++.h>

using namespace std;

const int N = 8080;

bool dp[N][N];

bool cek(int sum, const vector<int>& c) {
  memset(dp, 0, sizeof dp);
  int tot = 0;
  for (int x : c)
    tot += x;
  dp[0][0] = 1;
  for (int i = 0; i < c.size(); ++i) {
    for (int j = 0; j <= tot; ++j) {
      if (!dp[i][j]) continue;
      dp[i+1][j+c[i]] = 1;
      dp[i+1][abs(j-c[i])] = 1; 
    }
  }
  return dp[c.size()][sum];
}

char s[N];

int main() {
  scanf("%s", s);
  int x, y;
  scanf("%d %d", &x, &y);
  int n = strlen(s);
  int i = 0;
  while (i < n && s[i] == 'F') x--, i++;
  bool datar = 1;
  int cnt = 0;
  vector<int> hor, ver;
  while (i < n) {
    if (s[i] == 'T') {
      if (cnt > 0) {
        if (datar)
          hor.push_back(cnt);
        else
          ver.push_back(cnt);
      }
      cnt = 0;
      datar ^= 1;
    }
    else
      cnt++;
    i++;
  }
  if (cnt > 0) {
    if (datar)
      hor.push_back(cnt);
    else
      ver.push_back(cnt);
  }
  bool ans = cek(abs(x), hor);
  ans &= cek(abs(y), ver);
  puts(ans ? "Yes" : "No");
  return 0;
}