#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;
int bit[N], n;
void upd(int x, int v) {
  for (; x <= n; x += x&(-x))
    bit[x] = max(bit[x], v);
}
int get(int x) {
  int ret = 0;
  for (; x; x -= x&(-x))
    ret = max(ret, bit[x]);
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    upd(i+1, a);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, x, v;
    scanf("%d %d", &t, &x);
    if (t == 1) {
      scanf("%d", &v);
      upd(x, v);
    }
    else
      printf("%d\n", get(x));
  }

  return 0;
}