#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  int last = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (t)
      last = i;
    else {
      if (i - last >= d) {
        last = i;
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}