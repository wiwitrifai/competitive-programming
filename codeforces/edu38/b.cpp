#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    ans = max(ans, min(a[i]-1, 1000000 - a[i]));
  }
  printf("%d\n", ans);
  return 0;
}