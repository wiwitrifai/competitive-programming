// Points: 9

#include <bits/stdc++.h>

using namespace std;

long long _c, cnt = 0;;
long long last;

set<long long> st;

long long _n;

bool debug = true;

long long ask(long long p) {
  if (p == last)
    return 0;
  ++cnt;
  assert(1 <= p && p <= _n);
  assert(!st.count(p));
  st.insert(p);
  long long diff = abs(p - last);
  last = p;

  if (debug)
    return diff >= _c;

  cout << "? " << p << endl;
  long long ans;
  cin >> ans;
  return ans;
}

void answer(long long ans) {
  if (debug) {
    assert(ans == _c);
    return;
  }
  assert(cnt <= 64);
  cout << "= " << ans << endl;
}

void solve_small(long long n, long long l, long long r) {
  ask(l++);
  long long ans = n;
  while (l <= r) {
    long long res;
    if (last < l)
      res = ask(r--);
    else
      res = ask(l++);
    if (res) {
      --ans;
    } else {
      break;
    }
  }
  answer(ans);
}

void solve(long long n) {
  _n = n;
  if (n <= 64) {
    solve_small(n, 1, n);
    return;
  }
  long long mid = 63, sisa = n - mid - 1;
  long long lef = 1 + (sisa / 2), rig = n - ((sisa + 1) / 2);
  assert((rig - lef) == mid);
  long long low = 1, hig = n;
  ask(rig);
  long long res = ask(lef);
  if (!res) {
    low = mid + 1;
    while (low < hig) {
      if (last == lef)
        res = ask(++rig);
      else
        res = ask(--lef);
      if (!res) {
        ++low;
      } else {
        break;
      }
    }
    answer(low);
  } else {
    solve_small(mid, lef, rig-1);
  }
}

int main() {
  for (long long i = 1; i <= 125; ++i) {
    for (_c = 1; _c <= i; ++_c) {
      // cerr << " n = " << i << ", c = " << _c << endl;
      cnt = 0;
      st.clear();
      solve(i);
    }
  }
  // cerr << " done " << endl;
  debug = false;

  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    long long n;
    scanf("%lld", &n);
    st.clear();
    cnt = 0;
//   _c = 1 + (rand() % n);
    solve(n);
  }
  return 0;
}
