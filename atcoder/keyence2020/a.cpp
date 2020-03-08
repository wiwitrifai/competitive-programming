#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);
  int ans = min((n + w - 1) / w, (n + h - 1) / h);
  printf("%d\n", ans);
  return 0;
}
