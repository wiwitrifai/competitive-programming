#include <bits/stdc++.h>

using namespace std;

int scramble(int x) {
  return (x ^ (x<<1)) & 255;
}
int unscramble(int x) {
  int ret = x & 1;
  bool ok = ret;
  for(int i = 2; i<256; i<<=1) {
    if(x & i)
      ok = !ok;
    if(ok)
      ret |= i;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    printf("%d ", unscramble(x));
  }
  printf("\n");

  return 0;
}