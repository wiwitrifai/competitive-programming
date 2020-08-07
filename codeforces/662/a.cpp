#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  int first = (n + 1) / 2;
  int second = first;
  if (n & 1)
    --second;
  int ans = min((first + 1) / 2 + (second + 2) / 2, (first + 2) / 2 + (second + 1) / 2);
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
