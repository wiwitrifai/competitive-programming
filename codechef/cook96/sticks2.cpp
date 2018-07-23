#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      ++mp[a];
    }
    int add = 0;
    for (auto it : mp) {
      int cnt = it.second-1;
      add = max(add, min(cnt, 2));
    }
    if (k <= add + mp.size() || k < 4)
      puts("-1");
    else {
      vector<pair<int, int> > res;
      for (auto it : mp) {
        int v = it.first, cnt = it.second-1;
        if (cnt == 0) continue;
        res.emplace_back(v, cnt);
      }
      int need = k - (int)mp.size();
      int a = -1, b = -1;
      int sum = 0;
      for (int i = 0; i < res.size() && sum < need; ++i) {
        sum += res[i].second;
        if (res[i].second >= 3)
          a = b = res[i].first;
        else {
          if (a < b)
            a = res[i].first;
          else
            b = res[i].first;
        }
      }
      long long ans = 1LL * a * b;
      assert(ans > 0);
      need -= 2;
      sum = 0;
      a = b = -1;
      for (int i = 0; i < res.size(); ++i) {
        if (sum < need) {
          sum += res[i].second;
          a = res[i].first;
        }
        else {
          if (res[i].second > 1) {
            b = res[i].first;
            break;
          }
        }
      }
      if (a > 0 && b > 0) {
        ans = min(ans, 1LL * a * b);
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}