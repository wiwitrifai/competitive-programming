#include <bits/stdc++.h>

using namespace std;

int main() {
  int n[2], rmin[2], lmax[2];
  for (int z = 0; z < 2; z++) {
    scanf("%d", &n[z]);
    rmin[z] = 1e9 + 7;
    lmax[z] = -1;
    for (int i = 0; i < n[z]; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      lmax[z] = max(lmax[z], l);
      rmin[z] = min(rmin[z], r);
    }
  }
  printf("%d\n", max(0, max(lmax[0]-rmin[1], lmax[1]-rmin[0])));
  return 0;
}