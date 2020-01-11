#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
pair<int, int> r[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &r[i].first, &r[i].second);
  }
  sort(r, r+n);
  multiset<int> lef, rig;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    lef.insert(r[i].first);
    rig.insert(r[i].second);
  }
  for (int i = 0; i < n; ++i) {
    lef.erase(lef.find(r[i].first));
    rig.erase(rig.find(r[i].second));
    ans = max(ans, r[i].second - r[i].first + 1 + max(0, *rig.begin() - *lef.rbegin() + 1));
    lef.insert(r[i].first);
    rig.insert(r[i].second);
  }
  int rmost = 1e9 + 7;
  for (int i = 0; i + 1 < n; ++i) {
    rmost = min(rmost, r[i].second);
    lef.erase(lef.find(r[i].first));
    rig.erase(rig.find(r[i].second));
    ans = max(ans, max(0, rmost - r[i].first + 1) + max(0, *rig.begin() - *lef.rbegin() + 1));
  }
  printf("%d\n", ans);
  return 0;
}
