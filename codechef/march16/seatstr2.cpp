#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

long long powmod(long long base, int pw) {
  if(pw < 0)
    return 0;
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}
long long fac[N], ifac[N];
int cnt[26];
char s[N];

int main() {
  fac[0] = 1;
  ifac[0] = 1;
  for(int i = 1; i< N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    ifac[i] = powmod(fac[i], mod-2);
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i<n; i++)
      cnt[s[i]-'a']++;
    long long permut = fac[n];
    long long p1 = 0, p2 = 0, p3 = 0, p4 = 0, p12 = 0;
    for(int i = 0; i<26; i++) {
      p4 += (3*p2*cnt[i] + p12*cnt[i] + (p1*cnt[i]*(cnt[i]-1)/2 % mod) + (p12*cnt[i]*(cnt[i]-1)/2 % mod)) % mod;
      p3 += p2*cnt[i] % mod;
      p2 += p1*cnt[i] % mod;
      p1 += cnt[i];
      p12 += cnt[i]*(cnt[i]-1)/2 % mod;
      permut *= ifac[cnt[i]];
      permut %= mod;
    }
    p2 %= mod;
    p3 %= mod;
    p4 %= mod;
    p4 = p2*(p2-1)/2 - p4;
    long long sim = (p2 + 2*p3 + p4 + 1) % mod;
    long long ans = permut * (permut - sim) % mod;
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}