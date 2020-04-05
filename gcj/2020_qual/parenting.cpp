#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int>> activities(n);
  for (int i = 0; i < n; ++i) {
    int s, e;
    scanf("%d %d", &s, &e);
    activities[i] = make_tuple(s, e, i);
  }
  string ans(n, 'C');
  sort(activities.begin(), activities.end());
  int c = 0, j = 0;
  for (auto it : activities) {
    int s, e, id;
    tie(s, e, id) = it;
    if (c <= s) {
      c = e;
    }
    else if (j <= s) {
      j = e;
      ans[id] = 'J';
    }
    else {
      puts("IMPOSSIBLE");
      return;
    }
  }
  cout << ans << '\n';
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
