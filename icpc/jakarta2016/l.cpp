/**
 *  ACM ICPC Regional Jakarta 2016 - L : Tale of a Happy Man
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<pair<int,int>, int> seg[N];

long long dp[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v;
    for (int i = 0; i < m; ++i) {
      int x, a, b, h;
      scanf("%d %d %d %d", &x, &a, &b, &h);
      seg[i] = {{b, a}, h};
      v.push_back(a);
      v.push_back(b);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(seg, seg+m);
    long long cur = 0;
    for (int i = 0, j = 0; i < v.size(); i++) {
      while (j < m && seg[j].first.first == v[i]) {
        cur = max(cur, seg[j].second + dp[lower_bound(v.begin(), v.end(), seg[j].first.second) - v.begin()]);
        j++;
      }
      dp[i] = cur;
    }
    printf("Case #%d: %lld\n", tc, cur);
  }
  return 0;
}