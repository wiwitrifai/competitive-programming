#include <bits/stdc++.h>

using namespace std;


vector<int> read_sequence(int k, int n, long long d) {
  vector<int> s(n);
  for (int i = 0; i < k; ++i)
    scanf("%d", &s[i]);
  long long a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  for (int i = k; i < n; ++i) {
    s[i] = ((a * s[i-2] + b * s[i-1] + c) % d);
  }
  return s;
}

const int mod = 1e9 + 7;

void solve() {
  int n, m, e, k;
  scanf("%d %d %d %d", &n, &m, &e, &k);
  vector<int> x = read_sequence(k, n, m);
  vector<int> y = read_sequence(k, n, m);
  vector<int> id = read_sequence(k, e, n * m + n);
  vector<int> w = read_sequence(k, e, int(1e9));
  long long tot = n * m + n;
  vector<int> all(n * m + n, 1);
  vector<set<pair<int, int>>> sbot(n), stop(n);
  vector<int> bot(n, 1);
  vector<int> top(n, 1);
  for (int c = 0; c < n; ++c) {
    if (x[c] > y[c])
      swap(x[c], y[c]);
    if (x[c] == y[c]) {
      bot[c] = -1;
    }
    for (int i = 0; i < m; ++i) {
      if (x[c] <= i && i < y[c]) {
        sbot[c].insert(make_pair(1, i));
      } else {
        stop[c].insert(make_pair(1, i));
      }
    }
  }
  set<pair<int, int>> outer;
  for (int i = 0; i < n; ++i) {
    outer.insert({1, n + i});
    outer.insert({min(bot[i], top[i]), i});
  }
  long long sum = n;
  long long ans = 1;
  for (int i = 0; i < e; ++i) {
    tot += w[i] - all[id[i]];
    if (id[i] < n * m) {
      int c = id[i] / m, r = id[i] - c * m;
      sum -= max(bot[c], top[c]);
      outer.erase(make_pair(min(bot[c], top[c]), c));
      if (x[c] <= r && r < y[c]) {
        sbot[c].erase(make_pair(all[id[i]], r));
        sbot[c].insert(make_pair(w[i], r));
        bot[c] = sbot[c].rbegin()->first;
      } else {
        stop[c].erase(make_pair(all[id[i]], r));
        stop[c].insert(make_pair(w[i], r));
        top[c] = stop[c].rbegin()->first;
      }
      all[id[i]] = w[i];
      outer.insert(make_pair(min(bot[c], top[c]), c));
      sum += max(bot[c], top[c]);
    } else {
      int r = id[i] - n * m;
      outer.erase(make_pair(all[id[i]], n+r));
      all[id[i]] = w[i];
      outer.insert(make_pair(all[id[i]], n+r));
    }
    long long cur = tot - sum - outer.rbegin()->first;
    cur %= mod;
    ans = ans * cur % mod;
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
