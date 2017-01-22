#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a+i, b+i);
  }
  long long sum = 0;
  long long ans = 0;
  for (int i = n-1; i >= 0; i--) {
    long long now = a[i] + sum;
    int r = now % b[i];
    r = (b[i]-r) % b[i];
    ans += r;
    sum += r;
  }
  printf("%lld\n", ans);

  return 0;
}