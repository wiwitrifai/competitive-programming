#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LN = 20, mod = 1e9 + 7;
const long long inf = 1e15;

long long sp[LN][N];
long long get(int l, int r) {
  int len = r-l+1;
  int lg = 31 - __builtin_clz(len);
  return max(sp[lg][l], sp[lg][r-(1<<lg)+1]);
}
int n, b[N];
inline long long arith(int l, int r) {
  long long res = 1LL * (r-l+1) * (l+r) / 2;
  res %= mod;
  return res;
}

long long ma[N << 2], mi[N << 2], sum[N << 2], sum2[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  ma[id] = mi[id] = inf;
  if (r-l < 2) {
    sum2[id] = 1LL * l * mi[id] % mod;
    sum[id] = mi[id] % mod;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  sum[id] = (sum[il] + sum[ir]) % mod;
  sum2[id] = (sum2[il] + sum2[ir]) % mod;
}

void upd(int id, int l, int r, long long val) {
  ma[id] = mi[id] = val;
  sum[id] = (val % mod) * (r-l) % mod;
  sum2[id] = (val % mod) * arith(l, r-1) % mod;
}

void update(int x, int y, long long z, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    if (ma[id] <= z) return;
    if (mi[id] >= z) {
      upd(id, l, r, z);
      return;
    }
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (mi[il] >= ma[id])
    upd(il, l, mid, ma[id]);
  if (mi[ir] >= ma[id])
    upd(il, l, mid, ma[id]);
  update(x, y, z, il, l, mid);
  update(x, y, z, ir, mid, r);
  mi[id] = min(mi[il], mi[ir]);
  ma[id] = max(ma[il], ma[ir]);
  sum[id] = (sum[il] + sum[ir]) % mod;
  sum2[id] = (sum2[il] + sum2[ir]) % mod;
}
long long calc(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    long long res = sum2[id];
    res = (res - sum[id] * (x-1)) % mod;
    if (res < 0) res += mod;
    return res;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (mi[il] >= ma[id])
    upd(il, l, mid, ma[id]);
  if (mi[ir] >= ma[id])
    upd(il, l, mid, ma[id]);
  return calc(x, y, il, l, mid) + calc(x, y, ir, mid, r);
}
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i), sp[0][i] = 1LL * (i+1) * b[i];
  for (int i = 0; i + 1 < LN; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= n; ++j)
      sp[i+1][j] = max(sp[i][j], sp[i][j+(1<<i)]);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = i;
    long long now = 1LL * b[i] * (i+1);
    while (l < r) {
      int mid = (l + r) >> 1;
      if (get(mid, i) <= now)
        r = mid;
      else
        l = mid+1;
    }
    int le = i - l;
    l = i+1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (get(i+1, mid) < now)
        l = mid+1;
      else
        r = mid;
    }
    int ri = l - i;
    now %= mod;
    long long cnt = (arith(1, le) * ri + arith(1, ri) * (le+1)) % mod;
    cerr << le << " " << ri << " " << cnt << endl;
    ans = (ans + cnt * now) % mod;
  }
  vector<pair<int, int> > vd;
  for (int i = n-1; i >= 0; --i) {
    int now = b[i], last = i;
    vector<pair<int, int> > vvd;
    for (auto it : vd) {
      int cur = gcd(b[i], it.first);
      if (cur != now) {
        vvd.emplace_back(now, last);
        now = cur;
        last = it.second;
      }
    }
    vvd.emplace_back(now, last);
    vd.swap(vvd);
    last = i;
    for (auto it : vd) {
      update(last, it.second+1, it.first * 1LL * (i+1));
      last = it.second+1;
    }
    cerr << i << " " << calc(i, n) << endl;
    ans = (ans - calc(i, n)) % mod;
    if (ans < 0) ans += mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}