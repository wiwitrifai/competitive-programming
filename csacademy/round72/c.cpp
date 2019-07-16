#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[N], a[N];
int que[N], x[N];
int ans[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), cnt[i] = a[i];
  for (int i = 0; i < q; ++i) {
    scanf("%d", que+i);
    if (que[i] == 1)
      scanf("%d", x+i), --cnt[--x[i]];
  }
  for (int i = q-1, j = q-1; i >= 0; --i) {
    if (que[i] == 1) continue;
    while (j > i && (que[j] == 2 || cnt[x[j]] >= 0)) --j;
    if (j > i) {
      ans[i] = x[j];
      ++cnt[x[j]];
      --j;
    }
  }
  for (int i = 0; i < q; ++i) if (que[i] == 2)
    printf("%d\n", ans[i]);
  return 0;
}
