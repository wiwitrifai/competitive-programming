#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<int> multiply(vector<int> & a, vector<int> & b, int maxlen = -1) {
  if (a.empty() || b.empty())
    return vector<int>();
  vector<int> ret(a.size() + b.size() - 1, 0);
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int j = 0; j < (int)b.size(); ++j) {
      ret[i+j] = (ret[i+j] + 1LL * a[i] * b[j]) % mod;
    }
  }
  while (!ret.empty() && ret.back() == 0) ret.pop_back();
  if (maxlen >= 0 && (int)ret.size() > maxlen)
    ret.resize(maxlen);
  return ret;
}

vector<int> power(vector<int> b, int k, int maxlen = -1) {
  vector<int> ret = {1};
  for (; k; k >>= 1, b = multiply(b, b, maxlen))
    if (k & 1)
      ret = multiply(ret, b, maxlen);
  return ret;
}

ostream& operator<<(ostream& os, vector<int> v) {
  os << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    os << v[i] << (i+1 == (int)v.size() ? ']' : ',');
  }
  return os;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> a(n), b(n, 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> poly(n, 1);
  poly = power(poly, k, n);
  reverse(poly.begin(), poly.end());
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < n; ++j)
      b[j] = 1LL * b[j] * a[j] % mod;
    long long ans = 0;
    for (int j = 0; j < n; ++j)
      ans = (ans + 1LL * b[j] * poly[j]) % mod;
    printf("%lld%c", ans, i == m ? '\n' : ' ');
  }
  return 0;
}
