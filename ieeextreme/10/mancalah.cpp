/**
  IEEExtreme Programming Contest 10
  Problem : Mancala's
  Solver  : Wiwit Rifa'i
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7, p = 37, p2 = 19, mod2 = 1e9 + 9;

long long powmod(long long b, long long pw, int m) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % m;
    b = (b * b) % m;
    pw >>= 1;
  }
  return ret;
} 

int a[N + 5], b[N+5];
long long pp[N], ip, pp2[N], ip2;
long long ih, ih2;

int backward(int offset, int len, int tz, long long h, long long h2, int depth = 0) {
  long long t1, t2;
  t1 = t2 = 0;
  for (int i = len-1; i >= 0; i--) {
    int id = (i + offset) % N;
    t1 = (t1 * p + b[id]) % mod;
    t2 = (t2 * p2 + b[id]) % mod2;
  }

  if (h == ih && h2 == ih2)
    return 1;
  if (h == -1 && h2 == -1) {
    h = ih;
    h2 = ih2;
  }
  // for (int i = 0; i < len; i++) {
  //   cerr << b[(offset + i) % N] << " ";
  // }
  // cerr << len << "|" << tz << " " << h << " " << h2 << endl;
  // cerr << h << " " << t1 << endl;
  assert(t1 == h && t2 == h2);
  if (b[offset] == 1 && tz != len)
    return depth;
  int cnt = 0;
  int poff = (offset + N - 1) % N;
  int ret = 0;
  bool ok = true;
  long long hh = (h * p) % mod, mp = p;
  long long hh2 = (h2 * p2) % mod2, mp2 = p2;
  for (int i = 0; i < len-tz; i++) {
    int id = (i + offset) % N;
    if (b[id] == 1) {
      ok = false;
      break;
    }
    b[id]--;
    if (b[id] == 1)
      cnt++;
    else
      cnt = 0;
    b[poff]++;
    hh = (hh + mod - mp + 1) % mod;
    hh2 = (hh2 + mod2 - mp2 + 1) % mod2;
    mp = (mp * p) % mod;
    mp2 = (mp2 * p2) % mod2;
    ret = max(ret, backward(poff, len+1, ((i+1 == len-tz) && b[id] == 1 ? (b[poff] == 1 && cnt == len-tz ? cnt + tz + 1 : cnt + tz) : tz), hh, hh2, depth+1));
  }
  if (ok && tz) {
    hh = (h * p - pp[len] + 1 + len) % mod;
    hh2 = (h2 * p2 - pp2[len] + 1 + len) % mod2;
    if (hh < 0)
      hh += mod;    
    if (hh2 < 0)
      hh2 += mod2;
    int bef = b[poff];
    b[poff] = len;
    for (int i = len-tz; i < len; i++) {
      b[(offset + i) % N] = 0;
    }
    ret = max(ret, backward(poff, len-tz+1, cnt, hh, hh2, depth+1));
  }
  for (int i = 0; i < b[poff]; i++) {
    int id = (i + offset) % N;
    b[id]++;
  }
  b[poff] = 0;
  //   for (int i = 0; i < len; i++) {
  //   cerr << b[(offset + i) % N] << " ";
  // }
  // cerr << len << "|" << tz << " " << h << " " << h2 << endl;
  // cerr << h << " " << t1 << endl;

  return ret;
}


int main() {
  ip = powmod(p, mod - 2, mod);
  ip2 = powmod(p2, mod2 - 2, mod2);
  pp[0] = 1;
  pp2[0] = 1;
  for (int i = 1; i < N; i++) {
    pp[i] = (pp[i-1] * p + 1) % mod;
    pp2[i] = (pp2[i-1] * p2 + 1) % mod2;
  }
  int n = 0;
  while (scanf("%d", a+n) == 1) {
    b[n] = a[n];
    n++;
  }
  long long h = 0, h2 = 0;
  for (int i = n-1; i >= 0; i--) {
    h = (h * p + a[i]) % mod;
    h2 = (h2 * p2 + a[i]) % mod2;
  }
  ih = h;
  ih2 = h2;
  for (int i = n-1; i >= 0; i--)
    a[i+1] -= a[i];
  map < pair<long long, long long> , int > mp;
  int id = 0;
  int now = 0;
  int cnt = 0;
  long long ans1 = 0;
  while (1) {
    if (mp.count({h, h2})) {
      ans1 = mp[{h, h2}];
      break;
    }
    mp[{h, h2}] = cnt++;
    now += a[id];
    h -= now;
    h2 -= now;
    if (h < 0)
      h += mod;
    if (h2 < 0)
      h2 += mod2;
    h = (h * ip + pp[now-1]) % mod;
    h2 = (h2 * ip2 + pp2[now-1]) % mod2;
    if (h < 0)
      h += mod;
    if (h2 < 0)
      h2 += mod2;
    a[id] = 0;
    id++;
    if (id >= N)
      id = 0;
    a[id]++;
    a[(id+now) % N]--;
  }
  cnt = 0;
  for (int i = n-1; i >= 0; i--)
    if (b[i] == 1)
      cnt++;
    else
      break;
    // cerr << ans1 << endl;
  int ans2 = 0;
  if (b[0] != 1 || (cnt == n && n > 1))
    ans2 = backward(0, n, cnt,-1, -1);
  printf("%lld %d\n", ans1, ans2);
  return 0;
}