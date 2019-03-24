#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<pair<int, int> > seg;
vector<int> val;

bool can(int x) {
  val.assign(seg.size(), 0);
  set<pair<int, int>> s;
  int last = 0;
  int cur = 0;
  for (auto pp : seg) {
    int l = pp.first, r = pp.second;
    while (!s.empty()) {
      auto it = s.begin();
      if (it->first <= l) {
        val[it->second] += max(it->first - last, 0);
        last = max(last, it->first);
        s.erase(it);
      }
      else
        break;
    }
    if (last < l) {
      if (!s.empty()) {
        val[s.begin()->second] += l - last;
      }
      last = l;
    }
    pair<int, int> now = make_pair(r, cur++);
    s.insert(now);
    auto it = s.lower_bound(now);
    if (it == s.begin())
      continue;
    --it;
    while (1) {
      if (val[it->second] >= x) {
        if (it == s.begin()) {
          s.erase(it);
          break;
        }
        else {
          auto bef = it;
          --it;
          s.erase(bef);
        }
      }
      else
        break;
    }
  }

  while (!s.empty()) {
    auto it = s.begin();
    val[it->second] += max(it->first - last, 0);
    last = max(last, it->first);
    s.erase(it);
  }

  bool ret = 1;
  int w = 0;
  for (int u : val) {
    if (u < x) {
      ret = 0;
    }
  }
  return ret;
}

void solve(int tc) {
  scanf("%d %d", &n, &q);
  seg.resize(q);
  int lo = 0, hi = n;
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    seg[i] = {l, r};
    hi = min(hi, r-l);
  }
  sort(seg.begin(), seg.end());
  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if (can(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  printf("Case #%d: %d\n", tc, hi);
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
