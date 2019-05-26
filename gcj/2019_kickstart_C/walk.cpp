#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

set<pair<int, int> > segr[N], segc[N];
char s[N];
char dir[] = "NSWE";

void remove(int r, int c) {
  {
    auto it = segr[r].lower_bound(make_pair(c+1, -1));
    if (it != segr[r].begin()) {
      --it;
      int lo = it->first, hi = it->second;
      segr[r].erase(it);
      if (lo < c) {
        segr[r].insert(make_pair(lo, c-1));
      }
      if (c < hi) {
        segr[r].insert(make_pair(c+1, hi));
      }
    }
  }
  {
    auto it = segc[c].lower_bound(make_pair(r+1, -1));
    if (it != segc[c].begin()) {
      --it;
      int lo = it->first, hi = it->second;
      segc[c].erase(it);
      if (lo < r) {
        segc[c].insert(make_pair(lo, r-1));
      }
      if (r < hi) {
        segc[c].insert(make_pair(r+1, hi));
      }
    }
  }
}

void solve(int tc) {
  int n, r, c, sr, sc;
  scanf("%d %d %d %d %d", &n, &r, &c, &sr, &sc);
  scanf("%s", s);
  for (int i = 1; i <= r; ++i) {
    segr[i].clear();
    segr[i].insert(make_pair(1, c));
  }
  for (int i = 1; i <= c; ++i) {
    segc[i].clear();
    segc[i].insert(make_pair(1, r));
  }
  remove(sr, sc);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'N') {
      auto it = segc[sc].lower_bound(make_pair(sr, -1));
      assert(it != segc[sc].begin());
      --it;
      sr = it->second;
    }
    else if (s[i] == 'S') {
      auto it = segc[sc].lower_bound(make_pair(sr+1, -1));
      sr = it->first;
    }
    else if (s[i] == 'W') {
      auto it = segr[sr].lower_bound(make_pair(sc, -1));
      assert(it != segr[sr].begin());
      --it;
      sc = it->second;
    }
    else {
      auto it = segr[sr].lower_bound(make_pair(sc+1, -1));
      sc = it->first;
    }
    remove(sr, sc);
  }
  printf("Case #%d: %d %d\n", tc, sr, sc);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
