#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    bool ans = 1;
    k *= 2;
    if ((n % k) == 0 && ((n/k) & 1))
      ans = 0;
    puts(ans ? "YES" : "NO");
  }
  return 0;
}