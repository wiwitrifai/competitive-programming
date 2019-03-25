#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ans[N];

void solve() {
  int n;
  scanf("%d", &n);
  map<int, vector<int>> mp;
  int maks = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    mp[a[i]].push_back(i);
  }
  vector<int> all;
  for (auto & it : mp) {
    maks = max(maks, (int)it.second.size());
    for (int u : it.second)
      all.push_back(u);
  }
  if (maks * 2 > n) {
    puts("No");
    return;
  }
  puts("Yes");
  for (int i = 0; i < n; ++i) {
    int id = all[(i+maks) % n];
    ans[id] = a[all[i]];
  }
  for (int i = 0; i < n; ++i) {
    assert(ans[i] != a[i]);
    printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  }
}

int main() {
  int tt = 1;
  scanf("%d", &tt);
  while (tt--) {
    solve();
  }
  return 0;
}
