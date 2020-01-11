#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
long long ans[N], add[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  long long sum = 0;
  sort(a, a+n);
  for (int i = 0; i < m; ++i) {
    sum += a[i];
    ans[i] = add[i] = sum;
  }
  for (int i = m; i < n; ++i) {
    ans[i] = ans[i-m];
    sum += a[i] - a[i-m];
    add[i] = add[i-m] + sum;
    ans[i] += add[i];
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", ans[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}
