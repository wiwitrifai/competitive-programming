#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd( b % a, a) : b;
}

int main() {
  long long l;
  while (scanf("%lld", &l) == 1) {
    if (l & 1)
      printf("0\n");
    else {
      l /= 2;
      set<pair<pair<long long, long long>, long long > > st;
      for (long long m = 1; m * m <= l; m++) {
        if (l % m) continue;
        long long k = l/m;
        for (long long z = 1; z * z <= k; z++) {
          if (k % z) continue;
          long long y = k/z;
          if (z > m) {
            long long n = z - m;
            if (n < m) {
              pair<pair<long long, long long>, long long > res = make_pair(make_pair((m * m - n * n) * y, 2LL * n * m * y), (n * n + m * m) * y);
              if (res.first.first > res.first.second)
                swap(res.first.first, res.first.second);
              st.insert(res);
            }
          }
          if (y != z && y > m) {
            long long n = y-m;
            if (n < m) {
              pair<pair<long long, long long>, long long > res = make_pair(make_pair((m * m - n * n) * z, 2LL * n * m * z), (n * n + m * m) * z);
              if (res.first.first > res.first.second)
                swap(res.first.first, res.first.second);
              st.insert(res);
            }
          }
        }
      }
      l *= 2;
      long long ans = 0;
      for (set<pair<pair<long long, long long>, long long > >::iterator it = st.begin(); it != st.end();it++) {
        long long a = it->first.first, b = it->first.second, c = it->second;
        if (a + b + c != l) continue;
        if (a <= 0 || b <= 0 || c <= 0) continue;
        if (a * a + b * b != c * c) continue;
        ans++;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}