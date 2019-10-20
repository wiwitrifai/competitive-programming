#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, q;
int p[N], r[N];
int val[N];
void read_input() {
  scanf("%d %d %d", &n, &m, &q);
  fill(val, val+n+1, 1);
  for (int i = 0; i < m; ++i) {
    scanf("%d", p+i);
    val[p[i]] = 0;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d", r+i);
  }
}

void solve() {
  for (int i = 1; i <= n; ++i) {
    for (int j = i+i; j <= n; j += i) {
      val[i] += val[j];
    }
  }
  long long ans = 0;
  for (int i = 0; i < q; ++i) {
    ans += val[r[i]];
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
