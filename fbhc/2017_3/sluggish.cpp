#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

int cnt[N];
int d[N];

void read(int * ar, int n) {
  for (int i = 0; i <= n; ++i)
    cnt[i] = 0;
  int k;
  scanf("%d %d", ar, &k);
  int pos = 1;
  while (k--) {
    int r, l;
    scanf("%d %d", &r, &l);
    for (int i = 0; i < l; ++i) {
      scanf("%d", d+i);
    }
    while (r--) {
      for (int i = 0; i < l; ++i, ++pos)
        ar[pos] = ar[pos-1] + d[i];
    }
  }
  assert(pos == n);
}
int n;
int a[N], b[N];

void check() {
  fill(cnt, cnt+n+1, 0);
  for (int i = 0; i < n; ++i) {
    assert(1 <= a[i] && a[i] <= n);
    assert(1 <= b[i] && b[i] <= n);
    ++cnt[a[i]];
    ++cnt[b[i]];
  }
  for (int i = 1; i <= n; ++i)
    assert(cnt[i] == 2);
}

const int mod = 1e9 + 7;

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

void advance(int * ar, int & i, int & k) {
  while (i < n) {
    if (i + 1 < n && ar[i] == ar[i+1]) {
      ++k;
      i += 2;
      continue;
    }
    if (i + 3 < n && ar[i] == ar[i+2] && ar[i+1] == ar[i+3]) {
      ++k;
      i += 4;
      continue;
    }
    break;
  }
}

int fac[N], inv[N];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

void prepare() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
  }
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-2; i > 0; --i) {
    inv[i] = 1LL * inv[i+1] * (i+1) % mod;
  }
}

long long C(int n, int k) {
  return (1LL * fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

void solve(int tc) {
  printf("Case #%d: ", tc);
  scanf("%d", &n);
  read(a, n);
  read(b, n);
  check();
  int ans = 1;
  int i = 0, j = 0;
  while (i < n || j < n) {
    int ka = 0, kb = 0;
    advance(a, i, ka);
    advance(b, j, kb);
    if (ka > 0 || kb > 0) {
      ans = 1LL * ans * C(ka+kb, ka) % mod;
      continue;
    }
    if (i < n && j < n & a[i] == b[j]) {
      ++i, ++j;
      continue;
    }
    if (i+1 < n && j+1 < n && a[i] == b[j+1] && b[j] == a[i+1]) {
      add(ans, ans);
      i += 2;
      j += 2;
      continue;
    }
    if (i + 2 < n && j < n && a[i] == a[i+2] && a[i+1] == b[j]) {
      add(ans, ans);
      i += 3;
      ++j;
      continue;
    }
    if (i < n && j + 2 < n && b[j] == b[j+2] && a[i] == b[j+1]) {
      add(ans, ans);
      ++i;
      j += 3;
      continue;
    }
    ans = 0;
    break;
  }
  printf("%d\n", ans);
}

int main() {
  clock_t startt = clock();
  prepare();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
    fflush(stdout);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}