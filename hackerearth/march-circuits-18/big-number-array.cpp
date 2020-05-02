#include <bits/stdc++.h>

using namespace std;

vector<int> mod = {int(1e9 + 7), int(1e9 + 9), int(1e9 + 7)};
vector<int> p = {101, 29, 31};
long long powmod(long long b, long long pw, int mod) {
  long long r = 1;
  for (; pw; pw >>= 1, b = b * b % mod)
    if (pw & 1)
      r = r * b % mod;
  return r;
}
struct hashs {
  vector<int> val;
  hashs(int v) : val(p.size()) {
    for (int i = 0; i < val.size(); ++i)
      val[i] = powmod(p[i], v, mod[i]);
  }
  hashs() : val(p.size()) {}
  hashs operator+(const hashs & h) const {
    hashs ret;
    for (int i = 0; i < p.size(); ++i)
      ret.val[i] = val[i] ^ h.val[i];
    return ret;
  }
  void reset() {
    for (int i = 0; i < val.size(); ++i)
      val[i] = 0;
  }
  bool operator==(const hashs & h) const {
    for (int i = 0; i < val.size(); ++i)
      if (val[i] != h.val[i])
        return false;
    return true;
  }
};

const int N = 1e5 + 5;
hashs seg[N << 2];
int n;

void build(int id = 1, int l = 0, int r = n) {
  seg[id].reset();
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

void add(int x, int y, hashs & h, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    seg[id] = seg[id] + h;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  add(x, y, h, il, l, mid);
  add(x, y, h, ir, mid, r);
}

hashs get(int x, int id = 1, int l = 0, int r = n) {
  if (r-l < 2)
    return seg[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    return seg[id] + get(x, il, l, mid);
  else
    return seg[id] + get(x, ir, mid, r);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d %d", &n, &q);
    build();
    while (q--) {
      int c, x, y;
      scanf("%d %d %d", &c, &x, &y); --x;
      if (c == 1) {
        int l, r;
        scanf("%d %d", &l, &r);
        ++r;
        hashs hl(l), hr(r);
        hl = hl + hr;
        add(x, y, hl);
      }
      else {
        --y;
        puts(get(x) == get(y) ? "YES" : "NO");
      }
    }
  }
  return 0;
}