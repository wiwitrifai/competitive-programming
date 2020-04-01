#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  scanf("%d", &k);
  printf("2 3\n");
  int maxi = (1 << 18) - 1;
  int cur = 1;
  while (cur <= k) cur <<= 1;
  printf("%d %d 0\n", maxi, k);
  printf("%d %d %d\n", cur, cur|k, k);
  return 0;
}
