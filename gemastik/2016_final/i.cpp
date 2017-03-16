#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int bit[N], n;
void upd(int x, int v) {
  for (; x <= n; x += x&(-x))
    bit[x] += v;
}
int get(int x) {
  int ret = 0;
  for (; x; x -= x&(-x))
    ret += bit[x];
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    memset(bit, 0, sizeof bit);
    int inv = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      inv += (i - get(x));
      inv &= 1;
      upd(x, +1);
    }
    puts(inv ? "TIDAK" : "YA");
  }
  return 0;
}