#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int to[N];
int a[N], b[N], c[N];
int bit[N];
int n;
void upd(int x, int v) {
  for (; x; x -= x&(-x))
    bit[x] += v;
}
int get(int x) {
  int ret = 0;
  for (; x <= n; x += x&(-x))
    ret += bit[x];
  return ret;
}


int main() {
#ifdef LOCAL
#else
  freopen("mincross.in", "r", stdin);
  freopen("mincross.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  for (int i = 1; i <= n; i++)
    scanf("%d", b+i);
  long long ans = 1e17;
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i <= n; i++)
      bit[i] = 0;
    for (int i = 1; i <= n; i++)
      to[a[i]] = i;
    long long now = 0;
    for (int i = 1; i <= n; i++) {
      c[i] = to[b[i]];
      now += get(c[i]);
      upd(c[i], 1);
    }
    ans = min(ans, now);
    for (int i = 1; i <= n; i++) {
      now += (n-c[i])-(c[i]-1);
      ans = min(ans, now);
    }
    for (int i = 1; i <= n; i++)
      swap(a[i], b[i]);
  }
  assert(ans >= 0);
  printf("%lld\n", ans);
  return 0;
}