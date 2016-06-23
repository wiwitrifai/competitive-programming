#include <bits/stdc++.h>


using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  long long n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  // if(a == b) {
  //   cout << (n/a) * max(p, q) << endl;
  //   return 0;
  // }
  long long ab = (a/gcd(a, b)) * b;
  long long nab = n/ab, na = n/a - nab, nb = n/b - nab;
  long long ans = na * p + nb * q + nab * max(p, q);
  cout << ans << endl; 
  return 0;
}