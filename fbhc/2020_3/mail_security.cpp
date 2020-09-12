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

void solve() {
  int n, m, k, x;
  scanf("%d %d %d %d", &n, &m, &k, &x);
  vector<int> s = read_sequence(k, n);
  vector<int> p = read_sequence(k, m);
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  sort(p.begin(), p.end());
  int low = 0, hig = min(n, m);
  while (low < hig) {
    int mid = (low + hig + 1) >> 1;
    bool ok = true;
    vector<int> match(m, -1);
    vector<int> used(n, -1);
    set<pair<int, int>> st;
    for (int i = mid-1, j = 0; i >= 0; --i) {
      while (j < n && s[j] >= x && s[j] >= p[i]) {
        st.insert(make_pair(s[j] % x, j));
        ++j;
      }
      match[i] = -1;
      auto it = st.lower_bound(make_pair(p[i] % x, -1));
      if (it != st.end()) {
        match[i] = it->second;
      } else if (j < n && s[j] < x && s[j] >= p[i]) {
        match[i] = j++;
      } else if (!st.empty()) {
        match[i] = st.begin()->second;
      }
      if (match[i] != -1) {
        assert(used[match[i]] == -1);
        int r = s[match[i]] % x;
        st.erase(make_pair(r, match[i]));
        st.erase(make_pair(r+x, match[i]));
        used[match[i]] = i;
      }
      if (match[i] == -1) {
        ok = false;
        break;
      }
    }
    long long tot = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      int cur = s[i];
      if (used[i] != -1) {
        cur -= p[used[i]];
        assert(cur >= 0);
      }
      cur /= x;
      tot += cur;
      cnt += (cur > 0) || used[i] != -1;
    }
    ok &= (cnt - 1 <= tot);
    if (ok)
      low = mid;
    else
      hig = mid - 1;
  }
  printf("%d\n", low);
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
