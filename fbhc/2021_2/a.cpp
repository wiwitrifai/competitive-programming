#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m);
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }
  multiset<int> changed, unchanged;
  auto rem = [&](multiset<int> &ms, int x) {
    auto it = ms.find(x);
    if (it == ms.end())
      return false;
    ms.erase(it);
    return true;
  };
  for (int i = 0; i < m; ++i) {
    unchanged.insert(s[i]);
  }
  int ans = 0;
  vector<bool> used(m, false);
  for (int i = 0; i < n; ++i) {
    used.assign(m, false);
    multiset<int> keep;
    for (int j = 0; j < m; ++j) {
      cin >> s[j];
      if (rem(changed, s[j])) {
        continue;
      }
      if (rem(unchanged, s[j])) {
        used[j] = 1;
        keep.insert(s[j]);
        continue;
      }
    }
    ans += changed.size();
    changed.clear();
    unchanged.swap(keep);
    for (int j = 0; j < m; ++j) {
      if (!used[j]) {
        changed.insert(s[j]);
      }
    }
    assert((int)(changed.size() + unchanged.size()) == m);
  }
  cout << ans << endl;
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
