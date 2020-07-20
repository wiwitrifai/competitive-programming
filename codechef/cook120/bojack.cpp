#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  printf("%d\n", 2 * n);
  for (int i = 0; i < n; ++i)
    printf("a");
  for (int i = 0; i < n; ++i)
    printf("b");
  printf("\n");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
