#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long m;
vector<long long> a;

void read_input() {
  scanf("%d %lld", &n, &m);
  a.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
}

int cnt[61][2];

void solve() {
  memset(cnt, 0, sizeof cnt);
  for (int i = 49; i >= 0; --i) {
    for (int j = 0; j < n; ++j) {
      ++cnt[i][(a[j] >> i) & 1];
    }
  }
  long long mini = 0;
  for (int i = 0; i <= 49; ++i)
    mini += (1LL << i) * min(cnt[i][0], cnt[i][1]);
  if (mini > m) {
    puts("-1");
    return;
  }
  long long ans = 0;
  for (int i = 49; i >= 0; --i) {
    mini -= (1LL << i) * min(cnt[i][0], cnt[i][1]);
    if (mini + (1LL << i) * cnt[i][0] <= m) {
      mini += (1LL << i) * cnt[i][0];
      ans |= 1LL << i;
    }
    else {
      mini += (1LL << i) * cnt[i][1];
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
