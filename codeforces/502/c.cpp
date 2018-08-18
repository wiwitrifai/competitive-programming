#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int ans[N];

int main() {
  int n;
  scanf("%d", &n);
  int best = 1, bb = n;
  for (int a = 1; a <= n; ++a) {
    int b = (n + a - 1) / a;
    if (bb + best > a + b) {
      best = a;
      bb = b;
    }
  }
  int a = best, b = bb;
  int k = 0;
  while (1) {
    int cnt = k + (n-k + a-1)/a;
    if (cnt >= b)
      break;
    ++k;
  }
  int now = 0;
  for (int i = 0; i < k; ++i)
    ans[i] = n-i;
  for (int i = n-1; i >= k; i -= a) {
    for (int j = max(k, i-a+1); j <= i; ++j)
      ans[j] = ++now;
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');

  return 0;
}