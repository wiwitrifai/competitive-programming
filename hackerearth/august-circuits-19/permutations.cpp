#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int N = 1e5 + 5, S = 5000, M = N / S + 1;

int a[N];
ordered_set st[M];
int pos[N + N];

int main() {
  int n;
  scanf("%d", &n);
  memset(pos, -1, sizeof pos);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    pos[a[i]] = i;
    st[a[i]/S].insert(i);
  }
  int ans = 0;
  int q;
  scanf("%d", &q);
  while (q--) {
#ifdef LOCAL
    ans = 0;
#endif
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      x ^= ans;
      y ^= ans;
      --x, --y;
      if (a[x] == a[y]) continue;
      st[a[x]/S].erase(x);
      st[a[y]/S].erase(y);
      swap(a[x], a[y]);
      swap(pos[a[x]], pos[a[y]]);
      st[a[x]/S].insert(x);
      st[a[y]/S].insert(y);
    }
    else {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      l ^= ans;
      r ^= ans;
      k ^= ans;
      --l;
      int cnt = 0, g = 0;
      while (g < M) {
        int le = st[g].order_of_key(l), ri = st[g].order_of_key(r);
        if (cnt + (S - ri + le) >= k)
          break;
        cnt += S - ri + le;
        ++g;
      }
      ans = g * S - 1;
      while (cnt < k) {
        ++ans;
        while (l <= pos[ans] && pos[ans] < r) ++ans;
        ++cnt;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
