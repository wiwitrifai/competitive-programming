#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;

int n, x[2][N];
int last[3][N];
int dp[N];
map< int, int > ds[2][N];

void upd(int t, int id, int nx, int val) {
  auto it = ds[t][id].find(nx);
  if (it == ds[t][id].end())
    ds[t][id][nx] = val;
  else
    ds[t][id][nx] = max(val, it->second);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", x[i]+j);
  map< long long, int > mp[3];
  for (int i = 0; i < 3; i++)
    mp[i][0] = n, last[i][n] = n+1;
  long long sum[3];
  memset(sum, 0, sizeof sum);
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      if (j != 1)
        sum[j] += x[0][i];
      if (j != 0)
        sum[j] += x[1][i];
      last[j][i] = n+1;
      if (mp[j].count(sum[j])) {
        last[j][i] = mp[j][sum[j]];
      }
      last[j][i] = min(last[j][i], last[j][i+1]);
      mp[j][sum[j]] = i;
    }
  }

  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; i++) {
    upd(1, i, last[0][i], dp[i] + 1);
    upd(0, i, last[1][i], dp[i] + 1);
    dp[last[2][i]] = max(dp[last[2][i]], dp[i] + 1); 
    dp[i+1] = max(dp[i+1], dp[i]);
    for (int j = 0; j < 2; j++) {
      for (auto it : ds[j][i]) {
        int b = j ^ 1;
        dp[it.first] = max(dp[it.first], it.second);
        if (last[j][i] < it.first)
          upd(j, last[j][i], it.first, it.second+1);
        else if (last[j][i] > it.first)
          upd(b, it.first, last[j][i], it.second+1);
        else
          dp[it.first] = max(dp[it.first], it.second+1);
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}