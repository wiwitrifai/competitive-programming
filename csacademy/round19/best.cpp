#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    sum += a[i];
  }
  int ans = 1e9;
  int now = 0;
  for (int i = 0; i < n-1; i++) {
    sum -= a[i];
    now += a[i];
    ans = min(ans, abs(sum-now));
  }
  printf("%d\n", ans);
  return 0 ;
}