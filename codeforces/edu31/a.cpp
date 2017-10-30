#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    t -= 86400-x;
    if (t <= 0 && ans == -1)
      ans = i+1;
  }
  printf("%d\n", ans);
  return 0;
}