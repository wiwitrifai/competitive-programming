#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<int>> candy, add;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  vector<int> val;
  vector<pair<int, int>> spell(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    val.push_back(l);
    val.push_back(r);
    spell[i] = {l, r};
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  candy.resize(val.size());
  add.resize(val.size());
  for (int i = 0; i < n; ++i) {
    spell[i].first = lower_bound(val.begin(), val.end(), spell[i].first) - val.begin();
    spell[i].second = lower_bound(val.begin(), val.end(), spell[i].second) - val.begin();
    for (int j = spell[i].first; j < spell[i].second; ++j)
      candy[j].push_back(i);
    add[spell[i].first].push_back(i);
  }
  vector<int> pos(n, -1);
  vector<int> dp(1 << k, 0), pre(1 << k, 0);
  for (int i = 0; i+1 < (int)val.size(); ++i) {
    int sz = candy[i].size(), nsz = 1 << sz;
    for (int mask = 0; mask < nsz; ++mask) {
      dp[mask] += (__builtin_popcount(mask) & 1) * (val[i+1] - val[i]);
    }
    pre.swap(dp);
    for (int j = 0; j < (int)candy[i+1].size(); ++j) {
      pos[candy[i+1][j]] = j;
    }
    fill(dp.begin(), dp.end(), 0);
    for (int mask = 0; mask < nsz; ++mask) {
      int cur = 0;
      for (int j = 0; j < sz; ++j) {
        if (mask & (1 << j)) {
          int to = pos[candy[i][j]];
          if (to == -1) continue;
          cur |= 1 << to;
        }
      }
      dp[cur] = max(dp[cur], pre[mask]);
    }
    sz = candy[i+1].size(), nsz = 1 << sz;
    for (int x : add[i+1]) {
      int p = 1 << pos[x];
      for (int mask = 0; mask < nsz; ++mask) {
        dp[mask | p] = max(dp[mask | p], dp[mask]);
      }
    }
    for (int j = 0; j < (int)candy[i+1].size(); ++j) {
      pos[candy[i+1][j]] = -1;
    }
  }
  printf("%d\n", dp[0]);
  return 0;
}
