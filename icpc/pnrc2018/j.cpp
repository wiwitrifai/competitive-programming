#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  int mak = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    mak = max(mak, x*s);
  }
  printf("%d\n", (mak + 999) / 1000);
  return 0;
}
