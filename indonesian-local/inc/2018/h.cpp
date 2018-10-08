#include <bits/stdc++.h>

using namespace std;

long long cnt[20][10];

long long calc(long long x) {
  vector<int> d;
  while (x) {
    d.push_back(x % 10);
    x /= 10;
  }
  long long ret = 0;
  int last = 0;
  for (int i = d.size()-1; i >= 0; --i) {
    if (d[i] == 0) continue;
    ret += cnt[i][d[i]] + (last & 1);
    last = d[i];
  }
  return ret;
}

int main() {
  cnt[0][1] = 0;
  for (int i = 2; i <= 9; ++i) {
    cnt[0][i] = cnt[0][i-1] + ((i-1) & 1);
  }
  for (int i = 1; i < 20; ++i) {
    cnt[i][1] = cnt[i-1][9] + cnt[i-1][1] + 1;
    for (int j = 2; j <= 9; ++j) {
      cnt[i][j] = cnt[i][j-1] + cnt[i][1] + ((j-1) & 1);
    }
  }
  long long a, b;
  scanf("%lld %lld", &a, &b);
  long long odd = calc(b+1) - calc(a);
  long long even = b - a + 1 - odd;
  printf("%lld %lld\n", odd, even);
  return 0;
}