#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = (n * m + 1) / 2;
    printf("%d\n", ans);
  }
  return 0;
}
