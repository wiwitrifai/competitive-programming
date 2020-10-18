#include <bits/stdc++.h>

using namespace std;

char buffer[1024];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> g(k);
  int smask = 0;
  for (int i = 0; i < 4; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    smask |= 1 << x;
  }
  for (int i = 0; i < k; ++i) {
    scanf("%s", buffer);
    int mask = 0;
    for (int j = 0; j < k; ++j) {
      if (buffer[j] == '1')
        mask |= 1 << j;
    }
    g[i] = mask;
  }
  int nmask = 1 << k;
  vector<int> state;
  vector<vector<int>> pos;
  int sid = -1;
  for (int mask = 0; mask < nmask; ++mask) {
    if (__builtin_popcount(mask) != 4) continue;
    if (mask == smask)
      sid = state.size();
    state.push_back(mask);
    int combined = 0;
    for (int i = 0; i < k; ++i) {
      if (mask & (1 << i)) {
        combined |= g[i];
      }
    }
    vector<int> p;
    for (int i = 0; i < k; ++i) {
      if (combined & (1 << i)) {
        p.push_back(i);
      }
    }
    pos.push_back(p);
  }
  vector<vector<int>> trans(state.size());
  for (int i = 0; i < (int)state.size(); ++i) {
    for (int j = 0; j < (int)state.size(); ++j) {
      int d = state[i] & state[j];
      if (__builtin_popcount(d) >= 3) {
        trans[i].push_back(j);
      }
    }
  }
  vector<vector<int>> cnt;
  cnt.push_back(vector<int>(k, 0));
  for (int i = 0; i < n; ++i) {
    int t, x;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &x);
      --x;
      ++cnt.back()[x];
    } else {
      cnt.push_back(vector<int>(k, 0));
    }
  }
  vector<int> dp(state.size(), -1), tmp = dp;
  dp[sid] = 0;
  for (auto & c : cnt) {
    for (int i = 0; i <(int) dp.size(); ++i) {
      if (dp[i] < 0) continue;
      for (int p : pos[i]) {
        dp[i] += c[p];
      }
    }
    fill(tmp.begin(), tmp.end(), -1);
    for (int i = 0; i < (int)dp.size(); ++i) {
      if (dp[i] < 0) continue;
      for (int u : trans[i]) {
        tmp[u] = max(tmp[u], dp[i]);
      }
    }
    dp.swap(tmp);
  }
  int ans = *max_element(dp.begin(), dp.end());
  printf("%d\n", ans);
  return 0;
}
