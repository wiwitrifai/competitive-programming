#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int s[N];
long long sum[N];

void solve(int tc) {
  long long ans = 1e18;
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; ++i)
    scanf("%d", s+i);
  sort(s, s+n);
  sum[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i+1] = sum[i] + s[i];
  }
  for (int i = p; i <= n; ++i) {
    long long cur = 1LL * s[i-1] * p - sum[i] + sum[i-p];
    ans = min(ans, cur);
  }
  printf("Case #%d: %lld\n", tc, ans);
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
