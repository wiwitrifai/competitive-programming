#include <bits/stdc++.h>

using namespace std;

vector<int> xa, xb, ya, yb;

void upd(int id, int a, int b, int c, int d) {
  xa[id] = a;
  xb[id] = b;
  ya[id] = c;
  yb[id] = d;
}

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> a(k);
  xa.assign(k, -1);
  xb.assign(k, -1);
  ya.assign(k, -1);
  yb.assign(k, -1);
  vector<int> s(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
    assert(a[i] == (1 << i));
  }
  vector<int> hig(5, 0), offs(6, 0);
  for (int i = 0; i < 5; ++i) {
    offs[i+1] = offs[i] + (1 << (i * 3));
  }
  for (int i = 0; i < 30; ++i) {
    int y = i % 3, x = i - y;
    if (i >= 15) {
      x -= 15;
      y += 15;
    }
    assert((x % 3) == 0);
    x /= 3;
    assert(0 <= x && x < 5);
    upd(i, offs[x], offs[x] + (1 << (x * 3)), hig[x], hig[x] + (1 << y));
    hig[x] += 1 << y;
  }
  for (int i = 0; i < 5; ++i)
    assert(hig[i] == m);
  assert(offs.back() == n);
  for (int i = 0; i < k; ++i) {
    if (xa[i] > xb[i]) {
      swap(xa[i], xb[i]);
    }
    if (ya[i] > yb[i]) {
      swap(ya[i], yb[i]);
    }
    printf("%d %d %d %d\n", xa[i], xb[i], ya[i], yb[i]);
  }
  return 0;
}
