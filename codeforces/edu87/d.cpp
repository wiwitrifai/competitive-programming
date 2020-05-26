#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int bit[N];

void upd(int x, int v) {
  for (; x < N; x += x&-x)
    bit[x] += v;
}

int find(int x) {
  int ret = 0;
  for (int i = (1 << 19); i; i >>= 1) {
    if (ret + i >= N) continue;
    if (bit[ret+i] < x) {
      ret += i;
      x -= bit[ret];
    }
  }
  return ret+1;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  int cnt = n;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    upd(a, +1);
  }
  for (int i = 0; i < q; ++i) {
    int k;
    scanf("%d", &k);
    if (k > 0) {
      upd(k, +1);
      ++cnt;
    } else {
      int val = find(-k);
      --cnt;
      upd(val, -1);
    }
  }
  int ans = cnt == 0 ? 0 : find(1);
  printf("%d\n", ans);
  return 0;
}
