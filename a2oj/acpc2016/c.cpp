#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int g, c, e;
    scanf("%d %d %d", &g, &c, &e);
    int need = max(e-c, 0);
    printf("%d\n", need * (2 * g - 1));
  }
  return 0;
}