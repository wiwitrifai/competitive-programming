#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> spots;

void read_input() {
  scanf("%d %d", &k, &n);
  spots.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &spots[i].first);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &spots[i].second);
  }
  sort(spots.begin(), spots.end());
}

void solve() {
  ++k;
  bool odd = k&1;
  k /= 2;
  long long ans = 1e18;
  set<pair<int, int>> lefsum, rigsum, rigoth;
  for (int i = 0; i < n; ++i) {
    rigoth.insert(make_pair(spots[i].first + spots[i].second, i));
  }
  long long sum = 0;
  auto moverig = [&]() {
    while (rigsum.size() < k) {
      if (rigoth.empty())
        return;
      auto it = rigoth.begin();
      sum += it->first;
      rigsum.insert(*it);
      rigoth.erase(it);
    }
  };
  auto movelef = [&]() {
    while (lefsum.size() > k) {
      auto it = --lefsum.end();
      sum -= it->first;
      lefsum.erase(it);
    }
  };
  moverig();
  if (odd) {
    for (int i = 0; i < n; ++i) {
      pair<int, int> cur = make_pair(spots[i].first + spots[i].second, i);
      if (rigoth.count(cur))
        rigoth.erase(cur);
      else {
        rigsum.erase(cur);
        sum -= cur.first;
        moverig();
      }
      if (lefsum.size() >= k && rigsum.size() == k) {
        ans = min(ans, sum + spots[i].second);
      }
      cur = make_pair(-spots[i].first + spots[i].second, i);
      sum += cur.first;
      lefsum.insert(cur);
      movelef();
    }
  }
  else {
    for (int i = 0; i < n; ++i) {
      pair<int, int> cur = make_pair(spots[i].first + spots[i].second, i);
      if (rigoth.count(cur))
        rigoth.erase(cur);
      else {
        rigsum.erase(cur);
        sum -= cur.first;
        moverig();
      }
      cur = make_pair(-spots[i].first + spots[i].second, i);
      sum += cur.first;
      lefsum.insert(cur);
      movelef();
      if (lefsum.size() >= k && rigsum.size() == k) {
        ans = min(ans, sum);
      }
    }
  }
  printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
