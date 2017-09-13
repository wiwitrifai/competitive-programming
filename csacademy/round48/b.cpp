#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n); 
  int mi = 0, ma = 0, now = 0;
  for (int i = 0; i < n; i++) {
    int t, x;
    scanf("%d %d", &t, &x);
    if (t)
      now -= x;
    else
      now += x;
    ma = max(now, ma);
    mi = min(now, mi);
  }
  printf("%d\n", ma-mi);
  return 0;
}