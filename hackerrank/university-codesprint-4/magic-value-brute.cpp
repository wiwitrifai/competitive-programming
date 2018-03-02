#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

int n, b[N];

long long gcd(long long x, long long y) {
  return x ? gcd(y % x, x) : y;
}

long long res[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  long long ans = 0;
  long long sub = 0, add = 0;
  for (int l = 0; l < n; ++l) {
    long long vma = 0;
    long long vmi = 0;
    bool nol = 0;
    for (int r = l; r < n; ++r) {
      vma = max(vma, 1LL * (r-l+1) * b[r]);
      if (!nol)
        vmi = gcd(vmi, b[r]); 
      if (b[r] == 0) {
        vmi = 0; nol = 1;
      }
      ans = (ans + ((vma - vmi) % mod) * (r-l+1)) % mod;
      sub += vmi * (r-l+1);
      add += vma * (r-l+1);
      res[r] += vma * (r-l+1);
    }
  }
  for (int i = 0; i < n; ++i)
    cerr << res[i] << endl;
  // cerr << endl;
  sub %= mod;
  add %= mod;
  cout << sub << " " << add << endl;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}