#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  vector<long long> a(3);
  for (int i = 0; i < 3; ++i) {
    scanf("%lld", &a[i]);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    char s[3];
    long long t;
    scanf("%s %lld", s, &t);
    a[s[0]-'a'] += t;
    long long ans = 0;
    for (int mask = 0; mask < 8; ++mask) {
      long long cur = 0;
      for (int j = 0; j < 3; ++j) {
        if (mask & (1 << j))
          cur = gcd(cur, a[j]);
      }
      ans += __builtin_popcount(mask) & 1 ? +cur : -cur;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
