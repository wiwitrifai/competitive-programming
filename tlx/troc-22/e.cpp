// Unsolved: I hate interactive... T_T

#include <bits/stdc++.h>

using namespace std;
long long ca, cb, cx, cy;

map<long long, int> mp;
set<long long> st[2];

int ask(long long x) {
  auto it = mp.find(x);
  if (it != mp.end())
    return it->second;
#ifdef LOCAL
  long long xbef = x;
  x += ca;
  x %= 2LL * cx;
  int res = (x >= cx);
  st[res].insert(xbef);
  return mp[xbef] = res;
#endif
  printf("%lld\n", x+1);
  fflush(stdout);
  int ret;
  scanf("? %d", &ret);
  st[ret].insert(x);
  return mp[x] = ret;
}

void answer(long long x, long long y, long long a, long long b) {
#ifdef LOCAL
  assert(x == cx);
  assert(y == cy);
  assert(a == ca);
  assert(b == cb);
#endif
  printf("! %lld %lld %lld %lld\n", x, y, a, b);
  exit(0);
}

long long calc(long long low, long long hig) {
  while (low + 1 < hig) {
    long long mid = (low + hig) / 2;
    bool selow = true;
    if (ask(low) == ask(mid)) {
      low = mid;
    } else {
      hig = mid;
    }
  }
  assert(ask(low) != ask(hig));
  return low;
}

int main() {
  long long n;
#ifdef LOCAL
  scanf("%lld %lld %lld %lld", &cx, &cy, &ca, &cb);
  n = cx * cy - ca - cb;
#else
  scanf("%lld", &n);
#endif
  long long res = calc(0, n-1);
  int c = ask(res);
  long long low, hig;
  bool ada = 0;
  auto it = st[!c].lower_bound(res+1);
  if (it != st[!c].begin()) {
    --it;
    low = *it;
    hig = res;
    ada = 1;
  }
  if (res < n - res) {
    low = res + 1;
    hig = n - 1;
  } else {
    low = 0;
    hig = res;
  }
  it = st[c].lower_bound(res+1);
  if (it != st[c].end()) {
    if (!ada) {
      low = res;
      hig = *it;
    } else {
      if (hig - low > *it - res) {
        low = res;
        hig = *it;
      }
    }
    ada = 1;
  }
  long long res2 = calc(low, hig);
  long long diff = res - res2;
  if (ask(res) == ask(res2))
    diff /= 2;
  set<long long> cand;
  cerr << mp.size() << endl;
  return 0;
}
