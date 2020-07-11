#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    printf("%d%c", 1, i+1 == n ? '\n' : ' ');
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
