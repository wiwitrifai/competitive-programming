#include <bits/stdc++.h>

using namespace std;

const int N = 2505;

int pos[N][N], dp[N], a[N];
string buf;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  cin.ignore();
  int p = 0;
  while (getline(cin, buf)) {
    string s;
    stringstream ss(buf);
    while (ss >> s) {
      a[++p] = s.size();
    }
  }
  
  int maxi = -1;
  int sum = 0;
  
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = i; j <= n; j++) {
      now += a[j];
      pos[i][j] = now;
      now++;
    }
    maxi = max(maxi, a[i]);
    sum += a[i];
  }
  sum += n - 1;
  
  int ans = 0, niki = sum;
  for (int space = maxi; space <= sum; space++) {
    vector<pair<int, int>> aw;
    for (int i = 1; i <= n; i++) {
      int j = i;
      while (j + 1 <= n && pos[i][j + 1] <= space) j++;
      aw.emplace_back(i, j);
      i = j;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = aw[0].first; i < aw[0].second; i++) dp[i] = 1;
    for (int i = 1; i < aw.size(); i++) {
      int q = aw[i-1].first;
      int j = aw[i-1].first;
      for (int p = aw[i].first; p < aw[i].second; p++) {
        while (q < aw[i-1].second && pos[j][q] < pos[aw[i].first][p] - 1) q++;
        dp[p] = 1;
        if (q < aw[i-1].second && abs(pos[j][q] - pos[aw[i].first][p]) <= 1) {
          dp[p] = max(dp[p], dp[q] + 1);
        }
        if (q+1 < aw[i-1].second && abs(pos[j][q+1] - pos[aw[i].first][p]) <= 1) {
          dp[p] = max(dp[p], dp[q+1] + 1);
        }
      }
    }
    for (int i = 1; i <= n; i++) if (dp[i] > ans) {
      ans = dp[i];
      niki = space;
    }
  }
  printf("%d %d\n", niki, ans);
  return 0;
}

