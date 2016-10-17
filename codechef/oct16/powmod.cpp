#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}

int main() {
  set < int > st;
  for (int i = 0; i < 100000; i++) {
    int d = rand() % mod;
    long long res = powmod(d, (mod-1)/2);
    st.insert(res);
    // if (res == 1)
    //   cerr << d << " " << res << endl;
  }
  for (int c : st) {
    cout << c << endl;
  }
  return 0;
}