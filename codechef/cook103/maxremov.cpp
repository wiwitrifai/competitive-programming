#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[N];
int l[N], r[N];
int sumk[N], sumk1[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", l+i, r+i);
      --l[i];
      ++cnt[l[i]];
      --cnt[r[i]];
    }
    int now = 0;
    for (int i = 0; i+1 < N; ++i) {
      now += cnt[i];
      sumk1[i+1] = sumk1[i];
      sumk[i+1] = sumk[i];
      if (now == k) {
        ++sumk[i+1];
      }
      else if (now == k+1)
        ++sumk1[i+1];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, sumk[N-1] - sumk[r[i]] + sumk[l[i]] + sumk1[r[i]] - sumk1[l[i]]);
    }
    printf("%d\n", ans);
  }
  return 0;
}