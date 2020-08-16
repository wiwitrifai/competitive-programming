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
  int n, m, k, s;
  scanf("%d %d %d %d", &n, &m, &k, &s);
  vector<int> p = read_sequence(k, n);
  vector<int> q = read_sequence(k, m);
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  auto calc = [&](int from, int lef, int rig) {
    long long ret = 1LL * s * (rig - lef + 1);
    if (p[from] <= q[lef]) {
      ret += q[rig] - p[from];
    } else if (p[from] >= q[rig]) {
      ret += p[from] - q[lef];
    } else {
      ret += q[rig] - q[lef];
      ret += min(abs(q[rig] - p[from]), abs(p[from] - q[lef]));
    }
    return ret;
  };
  long long len = max(q.back(), p.back()) - min(q[0], p[0]);
  long long low = 0, hig = len * 2LL + 1LL * s * m;
  while (low < hig) {
    long long mid = (low + hig) >> 1;
    int it = 0;
    for (int i = 0; i < n && it < m; ++i) {
      if (calc(i, it, it) > mid) continue;
      int lef = it, rig = m-1;
      while (lef < rig) {
        int cur = (lef + rig + 1) >> 1;
        if (calc(i, it, cur) <= mid)
          lef = cur;
        else
          rig = cur - 1;
      }
      it = lef + 1;
    }
    if (it >= m)
      hig = mid;
    else
      low = mid + 1;
  }
  printf("%lld\n", low);
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
