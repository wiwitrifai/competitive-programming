#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct BIT {
  int bit[N];
  BIT() {
    memset(bit, 0, sizeof bit);
  }
  void upd(int x, int v) {
    for (; x < N; x += x&-x)
      bit[x] += v;
  }
  int get(int x) {
    int ret = 0;
    for (; x; x -= x&-x)
      ret += bit[x];
    return ret;
  }
};

int pos[N], t[N], r[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  BIT sum, cnt;
  for (int i = 0; i < n; ++i) {
    scanf("%d", t+i);
    r[i] = i;
  }
  sort(r, r + n, [](int le, int ri) {
    return t[le] < t[ri];
  });
  for (int i = 0; i < n; ++i)
    pos[r[i]] = i;
  for (int i = 0; i < n; ++i) {
    int p = pos[i];
    int tot = m - t[i];
    int lo = 0, hi = n+1;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (sum.get(mid) > tot)
        hi = mid-1;
      else
        lo = mid;
    }
    printf("%d%c", i - cnt.get(lo), i == n-1 ? '\n' : ' ');
    cnt.upd(p+1, 1);
    sum.upd(p+1, t[i]);
  }
  return 0;
}
