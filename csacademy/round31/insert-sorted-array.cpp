#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  a[n] = x;
  sort(a, a+n+1);
  int ans = lower_bound(a, a+n+1, x)-a+1;
  printf("%d\n", ans);
  return 0;
}