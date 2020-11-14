#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", 2, i+1 == n ? '\n' : ' ');
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
