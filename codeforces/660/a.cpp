#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

void solve() {
  int n;
  scanf("%d", &n);
  if (n <= 6 + 10 + 14) {
    puts("NO");
    return;
  }
  int sisa = n - 6 - 10 - 14;
  int x = 6, y = 10, z = 14;
  if (sisa == 6 || sisa == 10 || sisa == 14) {
    ++z;
    --sisa;
  }
  printf("YES\n%d %d %d %d\n", x, y, z, sisa);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
