#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6, mod = 1e9 + 7;

char s[N];

int main() {
  long long bom, nol, sl, sr, dua;
  scanf("%s", s);
  bom = nol = sl = sr = dua = 0;
  if (s[0] == '*')
    bom = 1;
  else if (s[0] == '0')
    nol = 1;
  else if (s[0] == '1')
    sr = 1;
  else if (s[0] == '?') {
    bom = nol = sr = 1;
  }
  int n = strlen(s);
  for (int i = 1; i < n; i++) {
    long long nbom, nnol, nsl, nsr, ndua;
    nbom = nnol = nsl = nsr = ndua = 0;
    if (s[i] == '?') {
      nbom = (bom + sr + dua) % mod;
      nnol = (nol + sl) % mod;
      nsl = bom;
      nsr = (nol + sl) % mod;
      ndua = bom;
    }
    else if (s[i] == '*') {
      nbom = (bom + sr + dua) % mod;
    }
    else if (s[i] == '0') {
      nnol = (nol + sl) % mod;
    }
    else if (s[i] == '1') {
      nsl = bom;
      nsr = (nol + sl) % mod;
    }
    else
      ndua = bom;
    bom = nbom;
    nol = nnol; 
    sl = nsl;
    sr = nsr;
    dua = ndua;
  }
  long long ans = (bom + nol + sl) % mod;
  printf("%lld\n", ans);
  return 0;
}