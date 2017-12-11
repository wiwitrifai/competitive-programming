#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

vector<int> fac;

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  if (y % x) {
    puts("0");
    return 0;
  }
  y /= x;
  for (int d = 1; 1LL * d * d <= y; ++d) {
    if (y % d) continue;
    fac.push_back(d);
    int p = y/d;
    if (p != d)
      fac.push_back(p);
  }
  sort(fac.begin(), fac.end());
  fac.erase(unique(fac.begin(), fac.end()), fac.end());
  vector<int> ans;
  for (int i = 0; i < fac.size(); ++i) {
    int cur = powmod(2, fac[i]-1);
    for (int j = 0; j < i; ++j) {
      if (fac[i] % fac[j]) continue;
      cur += mod - ans[j];
      cur %= mod;
    }
    cur %= mod;
    if (cur < 0) cur += mod;
    ans.push_back(cur);
    // cerr << cur << " ";
  }
  printf("%d\n", ans.back());
  return 0;
}