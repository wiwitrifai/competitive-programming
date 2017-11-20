#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ma = 1LL << 32;
    a[0] = (ma + n - 1) / n + 3;
    long long now = ma - a[0] * 2 - n + 1;
    for (int i = 1; i < n; i++) {
      a[i] = min(a[0]-1, now);
      now -= a[i];
      a[i]++;
    }
    for (int i = 0; i < n; i++) {
      printf("%lld%c", a[i], i == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}