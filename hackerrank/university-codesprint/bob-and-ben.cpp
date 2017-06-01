#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int m, k;
      scanf("%d %d", &m, &k);
      ans ^= (m & 1) ? 1 : (m > 2 ? 2 : 0);
    }
    puts(ans ? "BOB" : "BEN");
  }
  return 0;
}