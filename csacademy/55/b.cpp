#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, r, k;
  scanf("%d %d %d", &n, &r, &k);
  int ans1 = 0, ans2 = 0;
  int z = min(r, k);
  ans1 = r - z + (k - z);
  z = min(n-r, k);
  ans2 = r + z - (k - z);
  printf("%d %d\n", ans1, ans2);
  return 0;
}