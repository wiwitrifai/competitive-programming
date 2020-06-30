#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int bit[N];

int get(int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += bit[x];
  return r;
}

void upd(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  while (k--) {
    bool changed = false;
    fill(bit, bit+n+2, 0);
    for (int i = 0; i < n; ++i) {
      int d = a[i];
      upd(max(i - d, 0), +1);
      upd(min(i + d + 1, n+1), -1);
    }
    for (int i = 0; i < n; ++i) {
      int res = get(i);
      if (a[i] != res) {
        changed = true;
        a[i] = res;
      }
    }
    if (!changed)
      break;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], i+1 == n ? '\n' : ' ');
  }
  return 0;
}
