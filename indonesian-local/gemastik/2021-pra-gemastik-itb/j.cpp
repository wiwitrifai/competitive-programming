#include <bits/stdc++.h>

using namespace std;

long long calc(long long x) {
  vector<int> bits;
  while (x) {
    bits.push_back(x & 1);
    x >>= 1;
  }
  int n = bits.size();
  long long ans = 0;
  for (int i = n-1; i >= 0; --i) {
    if (bits[i] == 0) continue;
    if (i & 1) {
      int cnt = i / 2;
      ans += 1LL << cnt;
    } else {
      int cnt = i / 2;
      ans += 1LL << cnt;
      break;
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    ++r;
    printf("%lld\n", calc(r) - calc(l));
  }
  return 0;
}
