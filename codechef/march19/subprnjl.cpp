#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

int bit[N];

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

int geti(int k) {
  int pos = 0;
  for (int i = 1 << 10; i; i >>= 1) {
    if (pos + i >= N) continue;
    if (bit[pos+i] >= k) continue;
    k -= bit[pos+i];
    pos += i;
  }
  return pos+1;
}

int a[N], c[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
    }
    int ans = 0;
    for (int len = 1; len <= n; ++len) {
      int m = (k + len - 1) / len;
      int pos = (k + m - 1) / m ;
      memset(c, 0, sizeof c);
      memset(bit, 0, sizeof bit);
      for (int i = 0; i < len; ++i) {
        ++c[a[i]];
        upd(a[i], +1);
      }
      for (int i = len; i <= n; ++i) {
        int now = geti(pos);
        int cnt = c[now];
        if (c[cnt] > 0)
          ++ans;
        if (i == n) break;
        int last = a[i- len];
        --c[last];
        upd(last, -1);
        ++c[a[i]];
        upd(a[i], +1);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}