#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[N], l, r;
long long cur;
int a[N];
long long dp[N], v[N];

void majul() {
  --cnt[a[l]];
  cur -= cnt[a[l]];
  l++;
}
void mundurl() {
  l--;
  cur += cnt[a[l]];
  cnt[a[l]]++;
}
void muncurr() {
  r--;
  --cnt[a[r]];
  cur -= cnt[a[r]];
}
void majur() {
  cur += cnt[a[r]];
  cnt[a[r]]++;
  r++;
}

void cocok(int le, int ri) {
  while (r < ri)
    majur();
  while (le < l)
    mundurl();
  while (r > ri)
    muncurr();
  while (le > l)
    majul();
}


void solve(int le, int ri, int lo, int hi) {
  if (le > ri) return;
  if (lo == hi) {
    for (int i = le; i <= ri; i++) {
      cocok(lo, i+1);
      dp[i] = cur + (lo == 0 ? 0 : v[lo-1]);
    }
    return;
  }
  int mid = (le + ri) / 2, best = lo;
  dp[mid] = 1e18;
  for (int i = lo; i <= min(mid, hi); i++) {
    cocok(i, mid+1);
    long long now = cur + (i == 0 ? 0 : v[i-1]);
    if (now < dp[mid]) {
      dp[mid] = now;
      best = i;
    }
  }
  solve(le, mid-1, lo, best);
  solve(mid+1, ri, best, hi);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  memset(cnt, 0, sizeof cnt);
  l = r = 0;
  cur = 0;
  for (int i = 0; i < n; i++) {
    cocok(0, i+1);
    dp[i] = cur;
  }
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < n; j++)
      v[j] = dp[j];
    solve(0, n-1, 0, n-1);
  }
  printf("%lld\n", dp[n-1]);
  return 0;
}