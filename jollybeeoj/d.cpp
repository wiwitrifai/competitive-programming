#include <bits/stdc++.h>

using namespace std;

const int N = 3;
const long long mod = 1LL << 31;

struct matrix {
  long long a[N][N];
  matrix() {
    memset(a, 0, sizeof a);
    for(int i = 0; i<N; i++)
      a[i][i] = 1;
  }
  const long long * operator[](int id) const{
    return a[id];
  }
  long long * operator[](int id) {
    return a[id];
  }
  void reset() {
    memset(a, 0, sizeof a);
  }
  void print() {
    for(int i = 0; i<N; i++) {
      for(int j = 0; j < N; j++)
        cout << a[i][j] << " ";
      cout << "\n";
    }
  }
};

matrix operator*(const matrix p, const matrix q) {
  matrix ret;
  for(int i = 0; i<N; i++)
  for(int j = 0; j<N; j++) {
    ret[i][j] = 0;
    for(int k = 0; k<N; k++) {
      ret[i][j] = (ret[i][j] + (p[i][k] * q[k][j] % mod)) % mod;
    }
  }
  return ret;
}

matrix powmat(matrix base, long long pw) {
  matrix ret;
  while(pw) {
    if(pw & 1)
      ret = ret * base;
    base = base * base;
    pw >>= 1;
  }
  return ret;
}



int main() {
  long long n;
  cin >> n;
  matrix p, q;
  p[1][1] = q[1][1] = 2;
  p[2][1] = p[1][2] = q[2][1] = q[1][2] = 1;
  q[0][1] = -1;
  p[0][1] = 1;
  matrix c, d;
  c.reset(); d.reset();
  c[1][0] = d[1][0] = d[2][0] = 1;
  long long genap = n/2, ganjil = (n+1)/2;
  d = powmat(p*q, genap/2) * d;
  c = powmat(p*q, ganjil/2) * c;
  if(genap & 1)
    d = q * d;
  if(ganjil & 1)
    c = q * c;
  long long ans = (c[0][0]*c[0][0] % mod) + (d[0][0]*d[0][0] % mod) % mod;
  ans %= mod;
  if(ans < 0)
    ans += mod;
  cout << ans << endl;

  return 0;
}