#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long pw) {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}

int main() {
  long long n = 0;
  int k;
  scanf("%d", &k);
  bool one = true, even = true;
  long long pw = 1;
  for(int i = 0; i<k; i++) {
    long long a;
    scanf("%I64d", &a);
    one &= (a == 1);
    even &= !(a & 1);
    a %= (mod-1);
    pw = (pw * a) % (mod-1);
  }
  if(one) {
    puts("0/1");
    return 0;
  }     
  long long q = powmod(2, (pw+mod-2) % (mod-1));
  long long p = q + (even ? 1 : -1);
  p %= mod;
  p = (p * powmod(3, mod-2)) % mod;
  p %= mod;
  if(p < 0)
    p += mod;
  cout << p << "/" << q << endl;
  return 0;
}