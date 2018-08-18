#include <bits/stdc++.h>

using namespace std;

const unsigned N = 1e8 + 5;

bitset<N> bs;
unsigned a, b, c, d;
unsigned f(unsigned x) {
  return ((a * x + b) * x + c) * x + d;
}
vector<unsigned> prime;

int main() {
  unsigned n;
  cin >> n >> a >> b >> c >> d;
  bs.reset();
  unsigned s = 1;
  while ((s+1u) * (s+1u) <= n) ++s;
  for (unsigned i = 2; i <= s; ++i) {
    if (bs[i]) continue;
    prime.push_back(i);
    for (unsigned j = i+i; j <= s; j += i)
      bs[j] = 1;
  }
  unsigned off = 2;
  unsigned ans = 0;
  while (off <= n) {
    unsigned to = min(n+1u, off+N);
    bs.reset();
    unsigned sz = to - off;
    for (unsigned p : prime) {
      unsigned e = off % p;
      e = p - e;
      if (e == p) e = 0;
      assert(((e + off) % p) == 0);
      if (e + off == p) e += p;
      for (; e < sz; e += p)
        bs[e] = 1;
    }
    for (unsigned i = 0; i < sz; ++i) {
      if (bs[i]) continue;
      unsigned now = i + off;
      unsigned cost = 0, cur = n/now;
      while (cur) {
        cost += cur;
        cur /= now;
      }
      ans += cost * f(now);
    }
    off = to;
  }
  cout << ans << endl;
  return 0;
}