#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 17;

long long sum[N];

int n, q, h[N], x[N << 1], y[N << 1];
int ans[N << 1];
int l[N], r[N];
queue<int> que[N << 1];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", h+i);
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", x+i, y+i);
    x[i] &= N - 1;
  }
  for (int i = 0; i < n; ++i) {
    l[i] = 0;
    r[i] = q;
  }
  for (int now = 0; now < 8; ++now) {
    int from = now << 14;
    int to = from + 16384, til = min(to, n);
    if (from >= til) break;
    bool ok = 1;
    for (int i = from; i < til; ++i)
      que[(l[i] + r[i]) >> 1].push(i);
    while (ok) {
      ok = 0;
      for (int i = from; i < to; ++i)
        sum[i] = 0;
      for (int i = 0; i < q; ++i) {
        if ((from & x[i]) == from) {
          sum[from | (x[i] & 16383)] += y[i];
        }
        while (!que[i].empty()) {
          int id = que[i].front(); que[i].pop();
          long long cur = 0;
          for (int j = id; j < to; j = (j+1)|id)
            cur += sum[j];
          if (cur >= h[id])
            r[id] = i;
          else
            l[id] = i+1;
          if (l[id] < r[id]) {
            que[(l[id] + r[id]) >> 1].push(id);
            ok = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    ans[l[i]]--;
  }
  ans[0] += n;
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
    if (i+1 < q)
      ans[i+1] += ans[i];
  }
  return 0;
}