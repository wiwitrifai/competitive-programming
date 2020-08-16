#include <bits/stdc++.h>

using namespace std;


vector<int> read_sequence(int k, int n) {
  vector<int> s(n);
  for (int i = 0; i < k; ++i)
    scanf("%d", &s[i]);
  long long a, b, c, d;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
  for (int i = k; i < n; ++i) {
    s[i] = ((a * s[i-2] + b * s[i-1] + c) % d) + 1;
  }
  return s;
}

const int mod = 1e9 + 7;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> l = read_sequence(k, n);
  vector<int> w = read_sequence(k, n);
  vector<int> h = read_sequence(k, n);
  for (int i = 0; i + 1 < n; ++i) {
    assert(h[i] <= h[i+1]);
  }
  set<pair<int, int>> intervals;
  set<pair<int, int>> heights;
  heights.insert(make_pair(0, 0));
  heights.insert(make_pair(mod, 0));
  long long perimeter = 0;
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    int lef = l[i], rig = l[i] + w[i];
    auto it = heights.lower_bound(make_pair(rig+1, -1));
    auto pre = it;
    --pre;
    int h_rig = pre->second;
    perimeter += abs(it->second - h_rig);
    while (it->first >= lef) {
      perimeter -= abs(it->second - pre->second);
      if (it->first <= rig) {
        heights.erase(it);
      }
      it = pre;
      --pre;
    }
    perimeter += abs(it->second - h[i]);
    perimeter += abs(h[i] - h_rig);
    perimeter %= mod;
    heights.insert(make_pair(lef, h[i]));
    heights.insert(make_pair(rig, h_rig));

    it = intervals.lower_bound(make_pair(lef, -1));
    if (it != intervals.begin())
      --it;
    int last = lef;
    while (it != intervals.end()) {
      if (it->second < lef) {
        ++it;
        continue;
      }
      if (it->first > rig)
        break;
      auto nxt = it;
      ++nxt;
      perimeter += max(0, it->first - last) * 2;
      lef = min(lef, it->first);
      rig = max(rig, it->second);
      last = it->second;
      intervals.erase(it);
      it = nxt;
    }
    intervals.insert(make_pair(lef, rig));
    perimeter += max(0, rig - last) * 2;
    perimeter %= mod;

    if (perimeter < 0)
      perimeter += mod;
    ans = (ans * perimeter) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
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
