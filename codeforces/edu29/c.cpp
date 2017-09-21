#include <bits/stdc++.h>

using namespace std;

long long k;
int a, b;
int x[3][3], y[3][3];

pair<int,int > score(int p, int q) {
  if (p == q)
    return make_pair(0, 0);
  if (((p + 1) % 3) == q)
    return make_pair(0, 1);
  return make_pair(1, 0);
}

int main() {
  cin >> k >> a >> b;
  a--; b--;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", x[i]+j);
      x[i][j]--;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", y[i]+j);
      y[i][j]--;
    }
  }
  vector<pair<int,int> > state;
  vector<pair<int, int>> dp;
  state.emplace_back(a, b);
  dp.emplace_back(score(a, b));
  int start = -1;
  while (1) {
    int c = x[a][b], d = y[a][b];
    pair<int, int > cur = make_pair(c, d);
    a = c, b = d;
    for (int i = 0; i < state.size(); i++) if (cur == state[i]) {
      start = i;
      break;
    }
    if (start != -1)
      break;
    pair<int, int> res = score(a, b);
    dp.emplace_back(dp.back().first + res.first, dp.back().second + res.second);
    state.push_back(cur); 
  }
  if (k <= state.size()) {
    printf("%d %d\n", dp[k-1].first, dp[k-1].second);
    return 0;
  }
  k -= start;
  int loop = (int)state.size() - start;
  pair<int, int> vstart = start ? dp[start-1] : make_pair(0, 0), vloop = make_pair(dp.back().first - vstart.first, dp.back().second - vstart.second);
  pair<long long, long long > ans = vstart;
  long long cnt = k/loop;
  ans.first += cnt * vloop.first;
  ans.second += cnt * vloop.second;
  k %= loop;
  if (k) {
    k += start-1;
    ans.first += dp[k].first - vstart.first;
    ans.second += dp[k].second - vstart.second;
  }
  cout << ans.first << " " << ans.second << endl;
  return 0;
}