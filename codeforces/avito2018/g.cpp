#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 998244353;

set<pair<int, int> > st[N];
long long sum[N << 2], mul[N << 2], add[N << 2];
int n, q;

void upd(int id, int l, int r, long long m, long long a) {
  sum[id] = (sum[id] * m + 1LL * a * (r-l)) % mod;
  add[id] = (add[id] * m + a) % mod;
  mul[id] = mul[id] * m % mod;
}

void push(int id, int l, int r) {
  if (mul[id] == 1 && add[id] == 0) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, mul[id], add[id]);
  upd(ir, mid, r, mul[id], add[id]);
  mul[id] = 1;
  add[id] = 0;
}

void update(int x, int y, int m, int a, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, m, a);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  update(x, y, m, a, il, l, mid);
  update(x, y, m, a, ir, mid, r);
  sum[id] = (sum[il] + sum[ir]) % mod;
}

long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return sum[id];
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r);
  return (get(x, y, il, l, mid) + get(x, y, ir, mid, r)) % mod;
}

int main() {
  scanf("%d %d", &n, &q);
  memset(mul, 1, sizeof mul);
  for (int i = 0; i < q; ++i) {
    int t, l, r, x;
    // cerr << i << endl;
    scanf("%d %d %d", &t, &l, &r); --l;
    if (t == 1) {
      scanf("%d", &x);
      auto it = st[x].lower_bound(make_pair(l, -1));
      while (it != st[x].begin() && prev(it)->second > l) --it;
      if (it == st[x].end() || it->first >= r) {
        update(l, r, 1, 1);
        st[x].insert(make_pair(l, r));
      }
      else {
        int last = l;
        auto awal = it;
        while (it != st[x].end()) {
          if (it->first >= r)
            break;
          if (last < it->first) {
            update(last, it->first, 1, 1);
            last = it->first;
          }
          if (last < min(it->second, r)) {
            update(last, min(it->second, r), 2, 0);
            last = min(it->second, r);
          }
          ++it;
        }
        if (last < r)
          update(last, r, 1, 1), last = r;
        while (awal != st[x].begin() && prev(awal)->second >= l) --awal;
        while (it != st[x].end() && it->first <= r) ++it;
        int from = min(awal->first, l), to = r;
        while (awal != it) {
          to = max(awal->second, to);
          auto del = awal;
          ++awal;
          st[x].erase(del);
        }
        st[x].insert(make_pair(from, to));
      }
    }
    else {
      printf("%lld\n", get(l, r));
    }
  }   
  return 0;
}