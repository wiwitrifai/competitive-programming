#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> ranges;
  for (int i = 0; i < n; ++i) {
    int x, l;
    scanf("%d %d", &x, &l);
    ranges.emplace_back(x-l, x+l);
  }
  sort(ranges.begin(), ranges.end());
  int now = ranges[0].first;
  int ans = 0;
  for (auto it : ranges) {
    if (now <= it.first) {
      ++ans;
      now = it.second;
    }
    else
      now = min(now, it.second);
  }
  printf("%d\n", ans);
  return 0;
}
