#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long t;
  scanf("%d %lld", &n, &t);
  vector<pair<int, int>> val;
  vector<int> add;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ++a, ++b;
    if (a == 1)
      add.push_back(b);
    else
      val.emplace_back(a, b);
  }
  sort(val.begin(), val.end(), [](pair<int, int> le, pair<int, int> ri) {
    long long lef = 1LL * le.second * ri.first + ri.second;
    long long rig = 1LL * ri.second * le.first + le.second;
    return lef < rig;
  });
  ++t;
  vector<long long> dp;
  dp.push_back(1);
  for (auto it : val) {
    vector<long long> ndp = dp;
    ndp.push_back(t+1);
    for (int i = 0; i < (int)dp.size(); ++i) {
      ndp[i+1] = min(it.first * dp[i] + it.second, ndp[i+1]);
    }
    while (!ndp.empty() && ndp.back() > t)
      ndp.pop_back();
    dp.swap(ndp);
  }
  sort(add.begin(), add.end());
  vector<int> tot;
  int now = 0;
  tot.push_back(now);
  for (int x : add) {
    now += x;
    if (now > t) break;
    tot.push_back(now);
  }
  int ans = (int)dp.size()-1;
  for (int i = 0; i < (int)dp.size(); ++i) {
    int sisa = t - dp[i];
    int id = upper_bound(tot.begin(), tot.end(), sisa) - tot.begin()-1;
    ans = max(ans, i+id);
  }
  printf("%d\n", ans);
  return 0;
}
