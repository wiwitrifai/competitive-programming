#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], bit[N];

void upd(int x, int val) {
  for (; x; x -= x&(-x))
    bit[x] += val;
}
int get(int x) {
  int ret = 0;
  for (; x < N; x += x&(-x))
    ret += bit[x];
  return ret;
}

int ans[N], r[N], l[N];
vector< pair< int, int > > add[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    int last = 0;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a+i);
      if (a[i] != a[i-1])
        last = i-1;
      l[i] = last;
    }
    last = n+1;
    a[last] = 0;
    for (int i = n; i >= 1; i--) {
      if (a[i] != a[i+1])
        last = i+1;
      r[i] = last;
    }
    for (int i = 0; i <= n; i++)
      add[i].clear();
    for (int i = 1; i <= q; i++) {
      int ll, rr, k;
      scanf("%d %d %d", &ll, &rr, &k);
      ans[i] = 0;
      if (l[ll] != ll-1) {
        int to = min(r[ll], rr+1);
        if (to-ll >= k)
          ans[i]++;
        ll = to;
      }
      if (r[rr] != rr+1) {
        int to = max(ll-1, l[rr]);
        if (rr-to >= k)
          ans[i]++;
        rr = to;
      }
      if (ll <= rr) {
        add[rr].emplace_back(i, +k);
        add[ll-1].emplace_back(i, -k);
      }
    }
    memset(bit, 0, sizeof bit);
    for (int i = 1; i <= n; i++) {
      if (r[i] == i+1) {
        int k = i-l[i];
        upd(k, +1);
      }
      for (auto it : add[i]) {
        int id = it.first, k = it.second;
        if (k < 0) {
          k = -k;
          ans[id] -= get(k);
        }
        else
          ans[id] += get(k);
      }
    }
    for (int i = 1; i <= q; i++)
      printf("%d\n", ans[i]);
  }
  return 0;
} 