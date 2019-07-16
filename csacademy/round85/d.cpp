#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int cnt[66];
int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    ++cnt[a[i]];
  }
  int now = 0;
  for (int i = 0; i < 30; ++i) {
    cnt[i] += now;
    now = cnt[i] / 2;
    cnt[i] &= 1;
  }
  assert(now == 0);
  int ambil = 0;
  for (int i = 0; i < 30; ++i)
    if (cnt[i])
      ambil += 1 << i;
  int tot = 1 << 30;
  assert(ambil > 0 && ambil < tot);
  int sisa = tot - ambil;
  int all = 0;
  for (int i = 0; i < 30; ++i) {
    cnt[i] = (sisa >> i) & 1;
    all += cnt[i];
  }
  assert(all <= k);
  for (int i = 30; i > 0 && all < k; --i) {
    while (cnt[i] > 0 && all < k) {
      ++all;
      --cnt[i];
      cnt[i-1] += 2;
    }
  }
  assert(all == k);
  stack<int> st;
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
  for (int i = 0; i < 30; ++i) {
    while (cnt[i]-- > 0) {
      printf("%d", i);
      --all;
      if (all)
        printf(" ");
    }
  }
  printf("\n");
  return 0;
}