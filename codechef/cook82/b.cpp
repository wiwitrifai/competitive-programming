#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}

map< int, int > mp;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    for (int p = 2; 1LL * p * p <= a; p++) {
      if (a % p) continue;
      int cnt = 0;
      while ((a % p) == 0) a /= p, cnt++;
      mp[p] += cnt;
    }
    if (a > 1)
      mp[a]++;
  }
  bool ok = 1;
  for (auto it : mp) {
    if (it.second % n) ok = 0;
  }
  if (ok) {
    puts("justdoit");
    return 0;
  }
  long long ans = 1;
  n++;
  for (auto it : mp) {
    int p = (-it.second) % n;
    if (p < 0) p += n;
    ans = (ans * powmod(it.first, p)) % mod;
  }
  cout << ans << endl;
  return 0;
}