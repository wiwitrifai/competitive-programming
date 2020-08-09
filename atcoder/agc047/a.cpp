#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9, N = 2e5 + 5;
const long long modll = 1e18;

char buf[N];

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int n;
  scanf("%d", &n);
  map<long long, long long> cnt;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    int len = strlen(buf);
    long long cur = 0;
    int dig = 9;
    bool koma = false;
    for (int j = 0; j < len; ++j) {
      if (buf[j] == '.') {
        koma = true;
        continue;
      }
      cur = cur * 10 + (buf[j] - '0');
      dig -= koma;
    }
    for (int j = 0; j < dig; ++j) {
      cur *= 10;
    }
    cur = gcd(cur, modll);
    ++cnt[cur];
  }
  long long ans = 0;
  for (auto it : cnt) {
    for (auto oth : cnt) {
      if (oth.first < it.first) continue;
      int dua = 0, lima = 0;
      long long u = it.first;
      while ((u % 2) == 0) {
        u /= 2;
        ++dua;
      }
      while ((u % 5) == 0) {
        u /= 5;
        ++lima;
      }
      u = oth.first;
      while ((u % 2) == 0) {
        u /= 2;
        ++dua;
      }
      while ((u % 5) == 0) {
        u /= 5;
        ++lima;
      }
      if (min(dua, lima) < 18) continue;
      if (oth.first == it.first) {
        ans += it.second * (it.second - 1) / 2;
      } else {
        ans += it.second * oth.second;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
