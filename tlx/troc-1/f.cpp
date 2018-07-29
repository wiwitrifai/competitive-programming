// salah paham soal, harusnya hasilnya selalu positif integer

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, S = 200;

int n, a[N], b[N];
int dp[N];


int solve() {
  int best = 1;
  for (int d = 0; d < S; ++d) {
    for (int i = 0, dd = 0; i < n; ++i, dd += d)
      b[i] = a[i] - dd;
    sort(b, b+n);
    int last = b[0], cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] != last) {
        cnt = 0;
        last = b[i];
      }
      ++cnt;
      best = max(best, cnt);
    }
  }
  for (int i = 0; i < n; ++i) {
    int m = 0;
    int now = a[i];
    for (int j = 1;; ++j, now += S) {
      if (now > 1000000) break;
      if (j+i >= n) break;
      int v = a[j+i] - a[i];
      if (v < 0) continue;
      if (v % j) continue;
      int k = v / j;
      b[m++] = k;
    }
    int last = b[0], cnt = 0;
    sort(b, b+m);
    for (int j = 0; j < m; ++j) {
      if (b[j] != last) {
        cnt = 0;
        last = b[j];
      }
      ++cnt;
      best = max(best, cnt);
    }
  }
  return n - best;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i){
    scanf("%d", a+i);
  }
  int ans = solve();
  reverse(a, a+n);
  ans = min(ans, solve());
  printf("%d\n", ans);
  return 0;
}