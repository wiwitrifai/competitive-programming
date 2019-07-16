#include <bits/stdc++.h>

using namespace std;

long long a[3], b[3];
long long ans[3];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    a[i%3] += x;
  }
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    b[i%3] += x;
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ans[(i+j) % 3] += 1LL * a[i] * b[j];
    }
  }
  for (int i = 0; i < 3; ++i)
    printf("%lld%c", ans[i], i == 2 ? '\n' : ' ');
  return 0;
}
