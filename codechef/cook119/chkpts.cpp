#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, c;
  scanf("%d %d", &n, &c);
  vector<pair<pair<int, int>, int>> coors(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    int r = x % c;
    if (r < 0)
      r += c;
    coors[i] = {{y-x, r}, (x-r)/c};
  }
  sort(coors.begin(), coors.end());
  int cnt = 0;
  long long ans = 0;
  for (int i = 0; i < (int)coors.size();) {
    int j = i;
    while (j < (int)coors.size() && coors[j].first == coors[i].first)
      ++j;
    int l = i, r = j-1;
    ++cnt;
    while (l < r) {
      ans += coors[r].second - coors[l].second;
      ++l;
      --r;
    }
    i = j;
  }
  printf("%d %lld\n", cnt, ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
