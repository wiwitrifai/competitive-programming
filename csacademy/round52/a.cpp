#include <bits/stdc++.h>

using namespace std;

int main() {
  int last = 0;
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ans += a > last;
    last = max(a, last);
  }
  printf("%d\n", ans);
  return 0;
}