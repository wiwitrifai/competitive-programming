#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int ans[N];

int main() {
  long long n, k;
  cin >> n >> k;
  if (__builtin_popcountll(n) > k) {
    puts("No");
    return 0;
  }
  int y = 61;
  long long now = 1LL << 61;
  long long cnt = __builtin_popcountll(n);
  long long carry = 0;
  for (int i = 60; i >= 0; --i) {
    cnt += carry;
    carry += carry;
    if (cnt > k) break;
    y = i;
    now = 1LL << i;
    if (n & now)
      ++carry;
  }
  while (cnt + carry <= k) {
    n *= 2;
    --y;
    cnt += carry;
    carry += carry;
  }
  for (int i = 0; i < k-1; ++i) {
    while (n < 2) {
      n *= 2;
      now *= 2;
    }
    while (n <= now) {
      now /= 2;
      --y;
    }
    n -= now;
    ans[i] = y;
  }
  while (n < now) now /= 2, --y;
  n -= now;
  ans[k-1] = y;
  assert(n == 0);
  puts("Yes");
  for (int i = 0; i < k; ++i)
    printf("%d%c", ans[i], (i == k-1) ? '\n' : ' ');
  return 0;
}