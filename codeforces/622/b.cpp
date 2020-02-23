#include <bits/stdc++.h>

using namespace std;

int maxi(int x, int y, int n) {
  int lef = min(x-1, n-y), rig = min(y-1, n-x);
  return lef + rig + 1 + min(x-1-lef, y-1-rig);
}

int mini(int x, int y, int n) {
  int lef = min(x-1, max(n-y-1, 0)), rig = min(y-1, max(n-x-1, 0));
  return n - (lef + rig + min(n-y - lef, n-x-rig));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    int n;
    scanf("%d %d %d", &n, &x, &y);
    printf("%d %d\n", mini(x, y, n), maxi(x, y, n));
  }
  return 0;
}
