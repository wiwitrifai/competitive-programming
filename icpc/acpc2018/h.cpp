#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

int powmod(int b, int p, int m) {
  int r = 1;
  for (; p; p >>= 1, b = 1LL * b * b % m)
    if (p & 1)
      r = 1LL * r * b % m;
  return r;
}

int inv(int b, int p) {
  return powmod(b, p-2, p);
}


int solve(int s, int a, int b, int p, int x) {
  assert(a > 0);
  if (x == s)
    return 1;
  if (a == 1) {
    int n = (1LL * (x-s) * inv(b, p) + 1) % p;
    if (n < 0) n += p;
    return n;
  }
  int C = (1LL * s * (a-1) + b) % p;
  int D = (1LL * x * (a-1) + b) % p;
  if (C < 0) C += p;
  if (D < 0) D += p;
  if (C == 0) {
    if (D == 0)
      return 2;
    return 1e9;
  }
  D = 1LL * D * inv(C, p) % p;
  int sq = int((sqrt(p) + 2));
  map<int, int> mp;
  C = inv(a, p);
  for (int i = 0; i < sq; ++i) {
    if (mp.count(D)) break;
    mp[D] = i;
    D = 1LL * D * C % p;
  }
  int now = 1;
  int ans = 1e9;
  C = powmod(a, sq, p);
  for (int i = 0; i < sq; ++i) {
    auto it = mp.find(now);
    if (it != mp.end())
      ans = min(ans, i * sq + it->second + 1);
    now = 1LL * now * C % p;
  }
  return ans;
}

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  open_file("hawawshi.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, l, r, a, b, p;
    scanf("%d %d %d %d %d %d %d", &n, &x, &l, &r, &a, &b, &p);
    int cnt = 0, tot = r-l+1;
    for (int s = l; s <= r; ++s) {
      cnt += solve(s, a, b, p, x) <= n;
    }
    int d = gcd(cnt, tot);
    cnt /= d;
    tot /= d;
    printf("%d/%d\n", cnt, tot);
  }
  close_file();
  return 0;
}