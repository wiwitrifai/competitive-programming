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
  }
  s[0] = s[1] = 1;
  for (int i = 2; i < k; ++i) {
    s[i] = s[i-1] + s[i-2];
  }
  bool hor = true;
  int width = 1, height = 1;
  upd(0, 0, 1, 0, 1);
  for (int i = 1; i < k; ++i) {
    if (hor) {
      upd(i, 0, width, height, height + s[i]);
      height += s[i];
    } else {
      upd(i, width, width+s[i], 0, height);
      width += s[i];
    }
    hor = !hor;
  }
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
