#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n--) {
      int s;
      scanf("%d", &s);
      if (s < 60)
        ans++;
    }
    printf("Case #%d: %d\n", tc, ans);
  }

  return 0;
}