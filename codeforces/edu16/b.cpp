#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int x[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", x+i);
    sum += x[i];
  }
  sort(x, x+n);
  int ans = x[0];
  long long now = sum - 1LL * x[0] * n;
  for (int i = 0; i < n; i++) {
    long long cur = sum - 1LL * x[i] * (n - 2 * i);
    if (cur < now) {
      now = cur;
      ans = x[i];
    }
    sum -= 2 * x[i];
  }
  printf("%d\n", ans);
  return 0;
}