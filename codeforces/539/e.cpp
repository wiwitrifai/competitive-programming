#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 10;

vector<int> prime;
vector<long long> ppw[LG];

int mod;

long long powmod(long long b, long long p) {
  long long r= 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int ppow(int id, int p) {
  while (ppw[id].size() <= p) {
    ppw[id].push_back(1LL * ppw[id].back() * prime[id] % mod);
  }
  return ppw[id][p];
}

// ax + by = d
void extendedEuclidean(long long a, long long b, long long &x, long long &y, long long &d) {
  if(b == 0) { x = 1; y = 0; d = a; return; } 
  extendedEuclidean(b, a % b, x, y, d);
  long long xx, yy;
  xx = y;
  yy = x - (a/b)*y;
  x = xx; y = yy;
}

int inv(int v) {
  long long x, y, d;
  extendedEuclidean(v, mod, x, y, d);
  x %= mod;
  if (x < 0)
    x += mod;
  return x;
}

struct Node {
  vector<int> pw;
  long long sum, lazy;
} seg[N << 2];

int n, a[N];
inline long long add(long long x, long long y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}
void build(int id = 1, int l = 0, int r = n) {
  seg[id].sum = 0;
  seg[id].lazy = 1;
  seg[id].pw.assign(prime.size(), 0);
  if (r-l < 2) {
    seg[id].sum = a[l];
    seg[id].lazy = a[l];
    long long & cur = seg[id].lazy;
    for (int i = 0; i < prime.size(); ++i) {
      int p = prime[i];
      while ((cur % p) == 0) {
        cur /= p;
        ++seg[id].pw[i];
      }
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid,r );
  seg[id].sum = add(seg[il].sum, seg[ir].sum);
}

inline void upd(int id, long long v, vector<int> & pw, bool upd_sum = true) {
  seg[id].lazy = seg[id].lazy * v % mod;
  if (upd_sum)
    seg[id].sum = seg[id].sum * v % mod;
  for (int i = 0; i < prime.size(); ++i) {
    seg[id].pw[i] += pw[i];
    if (upd_sum)
      seg[id].sum = (seg[id].sum * ppow(i, pw[i])) % mod;
  }
}

inline void push(int id, int il, int ir) {
  bool ada = 0;
  if (seg[id].lazy != 1)
    ada = 1;
  for (int i = 0; i < prime.size(); ++i)
    ada |= seg[id].pw[i] > 0;
  if (!ada) return;
  upd(il, seg[id].lazy, seg[id].pw);
  upd(ir, seg[id].lazy, seg[id].pw);
  seg[id].lazy = 1;
  for (int i = 0; i < prime.size(); ++i)
    seg[id].pw[i] = 0;
}

vector<int> pw_cur;

void update_multiply(int x, int y, long long v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v, pw_cur);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update_multiply(x, y, v, il, l, mid);
  update_multiply(x, y, v, ir, mid, r);
  seg[id].sum = add(seg[il].sum, seg[ir].sum);
}

void update_divide(int x, long long v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    upd(id, v, pw_cur, false);
    seg[id].sum = seg[id].lazy;
    for (int i = 0; i < prime.size(); ++i) {
      seg[id].sum = (seg[id].sum * ppow(i, seg[id].pw[i])) % mod;
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  if (x < mid)
    update_divide(x, v, il, l, mid);
  else
    update_divide(x, v, ir, mid, r);
  seg[id].sum = add(seg[il].sum, seg[ir].sum);
}

long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return seg[id].sum;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  return add(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}


int main() {
  scanf("%d %d", &n, &mod);
  int now = mod;
  for (int i = 0; i < LG; ++i)
    ppw[i].resize(N);
  for (int p = 2; 1LL * p * p <= now; ++p) {
    if (now % p) continue;
    while ((now % p) == 0) now /= p;
    int id = prime.size();
    prime.push_back(p);
    ppw[id][0] = 1;
    for (int i = 1; i < N; ++i) {
      ppw[id][i] = 1LL * ppw[id][i-1] * p % mod;
    }
  }
  if (now > 1) {
    int p = now;
    int id = prime.size();
    prime.push_back(p);
    ppw[id][0] = 1;
    for (int i = 1; i < N; ++i) {
      ppw[id][i] = 1LL * ppw[id][i-1] * p % mod;
    }
  }
  assert(prime.size() < LG);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  build();
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      --l;
      int cur = x;
      pw_cur.assign(prime.size(), 0);
      for (int i = 0; i < prime.size(); ++i) {
        int p = prime[i];
        while ((cur % p) == 0) {
          ++pw_cur[i];
          cur /= p;
        }
      }
      update_multiply(l, r, cur);
    }
    else if (t == 2) {
      --l;
      int cur = r;
      pw_cur.assign(prime.size(), 0);
      for (int i = 0; i < prime.size(); ++i) {
        int p = prime[i];
        while ((cur % p) == 0) {
          --pw_cur[i];
          cur /= p;
        }
      }
      update_divide(l, inv(cur));
    }
    else {
      --l;
      long long ans = get(l, r);
      ans %= mod;
      if (ans < 0) ans += mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}