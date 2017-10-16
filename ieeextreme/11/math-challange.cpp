#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p, int m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p &1)
      r = r * b % m;
  return r;
}

int main() {
  int now = mod-1;
  long long euler = (now/2-1), mm = mod - 1;
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d",&a, &b, &c);
    int dua = 0;
    long long now = 1, bawah = 1;
    for (int i = 1; i <= b; i++) {
      int x = i;
      while ((x & 1) == 0) {
        dua++;
        x >>= 1;
      }
      now = (now * x) % mm;
    }
    for (int i = 1; i <= c; i++) {
      int x = i;
      while ((x & 1) == 0) {
        dua--;
        x >>= 1;
      }
      bawah = (bawah * x) % mm;
    }
    for (int i = 1; i <= b-c; i++) {
      int x = i;
      while ((x & 1) == 0) {
        dua--;
        x >>= 1;
      }
      bawah = (bawah * x) % mm;
    }
    now = (now * powmod(bawah, euler-1, mm)) % mm;
    now = (now * powmod(2, dua, mm)) % mm;
    if (now < 0) now += mm;
    now = powmod(a, now, mod);
    printf("%lld\n", now); 
  }
  return 0;
}