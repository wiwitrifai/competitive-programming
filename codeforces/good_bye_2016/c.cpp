#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6, inf = 1e8 + 7;
int d[N], c[N];

int main() {
  int n;
  scanf("%d", &n);
  int now = 0;
  int up = -inf, low = inf;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", c+i, d+i);
    if (d[i] == 1) {
      low = min(low, now);
    }
    else {
      up = max(up, now);
    }
    now += c[i];
  }
  if (low <= up) {
    puts("Impossible");
  }
  else if (up <= -inf)
    puts("Infinity");
  else
    printf("%d\n", now + 1899 - up);

  return 0;
}