#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 350;

long long g[55];
int n, dp[55];
long long best[55];
vector< pair<int, long long> > mask[55];

int calc(long long bmask) {
  int ret = 0;
  for (int i = 0; i < n; i++) if ((1LL << i) & bmask) {
    for (int j = 0; j < n; j++) if ((1LL << j) & bmask) {
      if (j == i) continue;
      if ((g[i] & (1LL<<j)) == 0) continue;
      long long other = g[i] & g[j] & bmask;
      if (other & (1LL << i)) other ^= (1LL<<i);
      if (other & (1LL << j)) other ^= (1LL<<j);
      ret += __builtin_popcountll(other);
    }
  }
  assert((ret % 3) == 0);
  return ret/3;
}

int main() {
  srand(time(0));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    g[i] = 0;
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      g[i] |= (1LL * x) << j;
    }
  }
  memset(dp, 0, sizeof dp);
  mask[0].emplace_back(0, 0);
  best[0] = 0;
  for (int i = 0; i < n; i++) {
    vector< pair< int, long long > > now;
    if (mask[i].size() <= 2 * MAGIC)
      now = mask[i];
    else {
      sort(mask[i].begin(), mask[i].end());
      for (int j = (int)mask[i].size()-MAGIC; j < mask[i].size(); j++)
        now.push_back(mask[i][j]);
      for (int j = 0; j < MAGIC; j++)
        now.push_back(mask[i][rand() % mask[i].size()]);
    }
    sort(now.begin(), now.end());
    now.erase(unique(now.begin(), now.end()), now.end());
    for (auto it : now) {
      long long cur = it.second;
      for (int j = 0; j < n; j++) {
        long long next = cur | (1LL << j);
        if (next == cur) continue;
        int res = calc(next);
        if (dp[i+1] < res) {
          dp[i+1] = res;
          best[i+1] = next;
        }
        mask[i+1].emplace_back(res, next);
      }
    }
  }
  long long ans = 0;
  int k = 1, tri = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[i] * k > tri * i) {
      tri = dp[i];
      k = i;
      ans = best[i];
    }
  }
  if (ans == 0) ans = 1;
  printf("%d\n", __builtin_popcountll(ans));
  for (int i = 0; i < n; i++)
    if (ans & (1LL << i))
      printf("%d ", i+1);
  printf("\n");
  return 0;
}