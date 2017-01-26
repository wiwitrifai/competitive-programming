#include <bits/stdc++.h>

using namespace std;

int v[3][10];
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
set< pair<int, pair<int, int> > > st[10];
int from;
void dfs(int x, int y, int c, int val = 0) {
  if (x < 0 || x > c || y < 0 || y > 2 || v[x][y])
    return;
  val |= 1 << (x * 3 + y);
  v[x][y] = 1;
  if (x == c) {
    st[c].insert(make_pair(val, make_pair(from, y)));
  }
  for (int i = 0; i < 4; i++) {
    dfs(x + dx[i], y + dy[i], c, val);
  }
  v[x][y] = 0;
}

const int N = 1e5 + 5, Z = 3;
const long long inf = 1e16;

int val[N][3];
long long dp[N][3];


int main() {
  memset(v, 0, sizeof v);
  int tot = 0;
  for (int i = 0; i < Z; i++) {
    for (int j = 0; j < 3; j++) {
      from = j;
      dfs(0, j, i);
    }
    tot += st[i].size();
  }
  int n;
  scanf("%d", &n);
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < n; i++) {
      scanf("%d", val[i]+j);
      dp[i][j] = -inf;
    }
  }
  for (int i = 0; i < min(Z, n); i++) {
    for (auto it : st[i]) {
      if (it.second.first != 0) continue;
      long long add = 0;
      for (int j = 0; j <= i; j++)
        for (int k = 0; k < 3; k++)
          if (it.first & (1<< (j * 3 + k)))
            add += val[j][k];
      dp[i][it.second.second] = max(dp[i][it.second.second], add);
    }
  }
  for (int i = 0; i < n; i++) {
    int ma = min(Z, n-i-1);
    for (int j = 0; j < ma; j++) {
      for (auto it : st[j]) {
        long long add = 0;
        for (int p = 0; p <= j; p++)
          for (int q = 0; q < 3; q++)
            if (it.first & (1 << (p * 3 + q)))
              add += val[i+1+p][q];
          dp[i+j+1][it.second.second] = max(dp[i+j+1][it.second.second], add+dp[i][it.second.first]);
      }
    }
  }
  cout << dp[n-1][2] << endl;
  return 0;
}