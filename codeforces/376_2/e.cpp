#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    sum += a[i];
  }
  long long ans = sum;
  for (int i = n-1; i > 1; i--) {
    sum -= a[i];
    ans = max(ans, sum - ans);
  }
  printf("%lld\n", ans);
  return 0;
}