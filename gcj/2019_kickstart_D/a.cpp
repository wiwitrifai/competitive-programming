#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, q;
int a[N], p[N], v[N];

void read_input() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    a[i] = __builtin_popcount(a[i]) & 1;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", p+i, v+i);
    v[i] = __builtin_popcount(v[i]) & 1;
  }
}

void solve() {
  set<int> idx[2];
  idx[0].clear();
  idx[1].clear();
  for (int i = 0; i < n; ++i) {
    idx[a[i]].insert(i);
  }
  for (int i = 0; i < q; ++i) {
    if (a[p[i]] != v[i]) {
      idx[a[p[i]]].erase(p[i]);
      a[p[i]] = v[i];
      idx[a[p[i]]].insert(p[i]);
    }
    if (i)
      printf(" ");
    if ((idx[1].size() & 1) == 0) {
      printf("%d", n);
    }
    else {
      int ans = max(*idx[1].rbegin(), n-*idx[1].begin()-1);
      printf("%d", ans);
    }
  }
  printf("\n");
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
