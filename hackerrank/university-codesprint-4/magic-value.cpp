#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}
int n, b[N];
inline long long arith(int l, int r) {
  long long res = 1LL * (r-l+1) * (l+r) / 2;
  res %= mod;
  return res;
}
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = b * r % mod;
  return r;
}
inline long long deret2(int x) {
  if (x <= 0) return 0;
  long long ret = 1LL * x * (x+1) % mod;
  ret = ret * (2 * x + 1) % mod;
  ret = ret * powmod(6, mod - 2) % mod;
  ret %= mod;
  return ret;
}
inline long long arith2(int l, int r) {
  return (deret2(r) - deret2(l-1)) % mod;
}

inline long long add(long long le, long long ri) {
  le += ri;
  if (le >= mod) le -= mod;
  return le;
}

long long sum[N << 2], sum2[N << 2], m[N << 2], c[N << 2], le[N << 2];

inline void upd(int id, int l, int r, long long vm, long long vc) {
  m[id] = vm;
  c[id] = vc;
  le[id] = 1LL * (r-l) * vm + vc;
  vm %= mod;
  vc %= mod;
  sum[id] = (arith(1, r-l) * vm + (r-l) * 1LL * vc) % mod;
  long long cur = (vc + vm * r) % mod;
  cur = (cur * arith(l, r-1)) % mod;
  sum2[id] = (cur - vm * arith2(l, r-1)) % mod;
  if (sum2[id] < 0) sum2[id] += mod;
}

inline void push(int id, int l, int r, int mid, int il, int ir) {
  if (m[id] == 0) return;
  upd(il, l, mid, m[id], c[id] + m[id] * (r-mid));
  upd(ir, mid, r, m[id], c[id]);
  m[id] = c[id] = 0;
}

inline bool update(int x, long long s, int id = 1, int l = 0, int r = n) {
  if (l >= x) return true;
  if (r <= x) {
    if (le[id] <= s * (x-l)) {
      upd(id, l, r, s, (x-r) * s);
      return true;
    }
  }
  if (r-l < 2) return false;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r, mid, il, ir);
  int ret = 0;
  if (ret = update(x, s, ir, mid, r))
    ret = update(x, s, il, l, mid);
  sum[id] = add(sum[il], sum[ir]);
  sum2[id] = add(sum2[il], sum2[ir]);
  le[id] = le[il];
  return ret;
}

inline long long get(int x, int id = 1 , int l = 0, int r = n) {
  if (l >= x) return 0;
  if (r <= x) {
    return (sum[id] * x - sum2[id]) % mod;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, l, r, mid, il, ir);
  return (get(x, il, l, mid) + get(x, ir, mid, r)) % mod;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  long long ans = 0;
  vector<pair<int, int> > vd;
  for (int i = n-1; i >= 0; --i) {
    int now = b[i], last = i;
    if (b[i] == 0) {
      vd.clear();
      continue;
    }
    vector<pair<int, int> > vvd;
    for (auto it : vd) {
      int cur = gcd(b[i], it.first);
      if (cur != now) {
        vvd.emplace_back(now, last);
        now = cur;
      }
      last = it.second;
    }
    vvd.emplace_back(now, last);
    vd.swap(vvd);
    last = i;
    for (auto it : vd) {
      ans = (ans - arith(last+1-i, it.second+1-i) * it.first) % mod; 
      if (ans < 0) ans += mod;
      last = it.second+1;
    }
  }
  for (int i = 0; i < n; ++i) {
    update(i+1, b[i]);
    ans = (ans + get(i+1)) % mod;
    if (ans < 0) ans += mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}