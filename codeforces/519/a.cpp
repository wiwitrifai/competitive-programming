#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0, ma = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
    ma = max(ma, a);
  }
  int ans = ma;
  sum *= 2;
  while (1LL * n * ans <= sum) ++ans;
  printf("%d\n", ans);
  return 0;
}