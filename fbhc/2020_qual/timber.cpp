#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int>> intervals;
  for (int i = 0; i < n; ++i) {
    int p, h;
    scanf("%d %d", &p, &h);
    intervals.emplace_back(p, p-h, 0);
    intervals.emplace_back(p+h, p, 1);
  }
  map<int, pair<int, int>> dp;
  sort(intervals.begin(), intervals.end());
  int ans = 0;
  for (auto & e : intervals) {
    int l, r, state;
    tie(r, l, state) = e;
    pair<int, int> cur = dp[r];
    pair<int, int> pre = dp[l];
    if (state) {
      cur.second = max(cur.second, pre.second + (r-l));
      ans = max(ans, cur.second);
    } else {
      cur.first = max(cur.first, max(pre.first, pre.second) + (r-l));
      ans = max(ans, cur.first);
    }
    dp[r] = cur;
  }
  printf("%d\n", ans);
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

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
