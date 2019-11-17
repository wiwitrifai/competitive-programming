#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

int l[N], r[N], x[N], cnt[N];
int n, p;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", l+i, r+i);
  }
  scanf("%d", &p);
  set<int> used;
  for (int i = 0; i < p; ++i) {
    scanf("%d", x+i);
    used.insert(x[i]);
  }
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < p; ++j)
      if (l[i] <= x[j] && x[j] <= r[i]) {
        ++cnt[i];
      }
    ok &= cnt[i] <= 2;
  }
  if (!ok) {
    puts("impossible");
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 2) continue;
    if (cnt[i] == 0) {
      int lef = l[i] + 1;
      while (used.count(lef)) ++lef;
      used.insert(lef);
      ans.push_back(lef);
      ++cnt[i];
    }
    if (i + 1 < n && cnt[i] == 1 && cnt[i+1] < 2 && r[i] == l[i+1] && !used.count(r[i])) {
      used.insert(r[i]);
      ans.push_back(r[i]);
      ++cnt[i];
      ++cnt[i+1];
    }
    if (cnt[i] < 2) {
      int rig = r[i] - 1;
      while (used.count(rig)) --rig;
      used.insert(rig);
      ans.push_back(rig);
      ++cnt[i];
    }
  }
  printf("%d\n", (int)ans.size());
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int)ans.size(); ++i){
    printf("%d%c", ans[i], i + 1 == (int)ans.size() ? '\n' : ' ');
  }
  return 0;
}
