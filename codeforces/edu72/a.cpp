#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int s, t, e;
    scanf("%d %d %d", &s, &t, &e);
    int now = s - t;
    int low = max(now - e, 1), high = now + e;
    if ((low & 1) != (high & 1))
      ++low;
    if (high < low) {
      puts("0");
      continue;
    }
    int cnt = (high - low) / 2 + 1;
    printf("%d\n", cnt);
  }
  return 0;
}
