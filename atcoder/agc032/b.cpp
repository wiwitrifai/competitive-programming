#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > ans;
  vector<vector<int> > sum;
  if (n & 1) {
    sum.push_back({n});
    for (int i = 1; n-i > i; ++i)
      sum.push_back({i, n-i});
  }
  else {
    for (int i = 1; n + 1 - i > i; ++i) {
      sum.push_back({i, n+1-i});
    }
  }
  for (int i = 0; i + 1 < sum.size(); ++i) {
    for (int x : sum[i]) {
      for (int y : sum[i+1]) {
        ans.emplace_back(x, y);
      }
    }
  }
  if (sum.size() > 2) {
    for (int x : sum[0]) {
      for (int y : sum.back()) {
        ans.emplace_back(x, y);
      }
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}