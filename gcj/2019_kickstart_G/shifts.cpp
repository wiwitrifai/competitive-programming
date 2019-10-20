#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int n, h;
int a[N], b[N];
int sa[1 << N], sb[1 << N];

void read_input() {
  scanf("%d %d", &n, &h);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
}

void process(int x[N], int sx[1 << N]) {
  int nmask = 1 << n;
  for (int mask = 0; mask < nmask; ++mask) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        sum = min(h, sum + x[i]);
      }
    }
    sx[mask] = (sum >= h);
  }
  for (int i = 0; i < n; ++i) {
    int cur = 1 << i;
    for (int mask = nmask - 1; mask >= 0; --mask) {
      if (mask & cur) {
        sx[mask] += sx[mask^cur];
      }
    }
  }
}

void solve() {
  int nmask = 1 << n;
  process(a, sa);
  process(b, sb);
  long long ans = 0;
  for (int mask = 0; mask < nmask; ++mask) {
    int cnt = n - __builtin_popcount(mask);
    if (cnt & 1)
      ans -= 1LL * sa[mask] * sb[mask];
    else
      ans += 1LL * sa[mask] * sb[mask];
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
