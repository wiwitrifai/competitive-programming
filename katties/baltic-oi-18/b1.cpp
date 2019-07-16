#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int cnt[N], a[N], mi[N];

int main() {
  int n, k, r;
  scanf("%d %d %d", &n, &k, &r);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < r; ++i) {
    int b, q;
    scanf("%d %d", &b, &q);
    mi[b] = q;
  }
  int cur = 0;
  for (int i = 0; i < k; ++i)
    cur += cnt[i] >= mi[i];
  int ans = n + 1;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && cur < k) {
      int x = a[j];
      if (cnt[x] < mi[x] && cnt[x]+1 >= mi[x])
        ++cur;
      ++cnt[x];
      ++j;
    }
    if (cur == k)
      ans = min(ans, j-i);
    else
      break;
    int x = a[i];
    if (cnt[x] >= mi[x] && cnt[x]-1 < mi[x])
      --cur;
    --cnt[x];
  }
  if (ans > n)
    puts("impossible");
  else
    printf("%d\n", ans);
  return 0;
}