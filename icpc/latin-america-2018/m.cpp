// TLE

#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int a[N];
int off[N], to[N];
int tmp[N];

const int pr[2] = {307, 311}, mod[] = {int(1e9 + 7), int(1e9+9)};
int pw[2][N];

long long powmod(long long b, int p, int m) {
  long long ret = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      ret = ret * b % m;
  return ret;
}

struct hashh {
  int v[2];
  hashh(int x) {
    v[0] = v[1] = x;
  }
  hashh() {
    memset(v, 0, sizeof v);
  }
  hashh operator<<(int x) {
    hashh ret;
    for (int i = 0; i < 2; ++i) {
      ret.v[i] = 1LL * v[i] * pw[i][x] % mod[i];
      if (ret.v[i] < 0)
        ret.v[i] += mod[i];
    }
    return ret;
  }
  // hashh operator>>(int x) {
  //   hashh ret;
  //   for (int i = 0; i < 2; ++i)
  //     ret.v[i] = 1LL * v[i] * inv[i][x] % mod[i];
  //   return ret;
  // }
  hashh operator+(hashh h) {
    hashh ret;
    for (int i = 0; i < 2; ++i) {
      ret.v[i] = v[i] + h.v[i];
      if (ret.v[i] >= mod[i])
        ret.v[i] -= mod[i];
    }
    return ret;
  }
  hashh operator-(hashh h) {
    hashh ret;
    for (int i = 0; i < 2; ++i) {
      ret.v[i] = v[i] + mod[i] - h.v[i];
      if (ret.v[i] >= mod[i])
        ret.v[i] -= mod[i];
    }
    return ret;
  }
  hashh operator=(hashh h) {
    for (int i = 0; i <2; ++i)
      v[i] = h.v[i];
    return *this;
  }
  bool operator==(hashh h) {
    return v[0] == h.v[0] && v[1] == h.v[1];
  }
};

hashh pre[N];

hashh chashh(int from, int off, int s) {
  if (s == 0)
    return hashh();
  hashh ret = pre[off+s-1];
  if (off > from)
    ret = ret - (pre[off-1] << s);
  return ret;
}

void solve(int l, int r) {
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1;
  solve(l, mid);
  solve(mid, r);
  int from = off[l], til = to[r-1];
  mid = off[mid];
  int s = 0;
  hashh now;
  for (int i = from; i < mid; ++i) {
    now = (now << 1) + hashh(a[i]);
    pre[i] = now;
  }
  now.v[0] = now.v[1] = 0;
  for (int i = mid; i < til; ++i) {
    now = (now << 1) + hashh(a[i]);
    pre[i] = now;
  }
  for (int i = from, j = mid; i < mid || j < til;) {
    int lo = 0, hi = min(mid-i, til-j);
    while (lo < hi) {
      int mi = (lo + hi + 1) >> 1;
      if (chashh(from, i, mi) == chashh(mid, j, mi))
        lo = mi;
      else
        hi = mi-1;
    }
    if (j+lo == til)
      tmp[s++] = a[i++];
    else if (i+lo == mid)
      tmp[s++] = a[j++];
    else if (a[i+lo] < a[j+lo])
      tmp[s++] = a[i++];
    else {
      assert(a[i+lo] > a[j+lo]);
      tmp[s++] = a[j++];
    }
  }
  for (int i = 0; i < s; ++i)
    a[from+i] = tmp[i];
}

int main() {
  pw[0][0] = pw[1][0] = 1;
  for (int i = 1; i < N; ++i) {
    pw[0][i] = pw[0][i-1] * pr[0] % mod[0];
    pw[1][i] = pw[1][i-1] * pr[1] % mod[1];
  }
  int n;
  int m = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int s;
    scanf("%d", &s);
    off[i] = m;
    while (s--) {
      scanf("%d", a+m++);
    }
    to[i] = m;
  }
  solve(0, n);
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    cerr << a[i] << " ";
    ans = 1LL * (ans + a[i]) * 365 % mod[0];
  }
  cerr << endl;
  if (ans < 0) ans += mod[0];
  printf("%lld\n", ans);
  return 0;
}