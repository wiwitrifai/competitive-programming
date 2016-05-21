#include <bits/stdc++.h>

using namespace std;

int main() {
  printf("0");
  int n;
  scanf("%d", &n);
  printf("%d\n", n);
  int p = 7;
  int mod = 23;
  int off = 1;
  int now = 11;
  for(int i = 0; i<n; i++) {
    printf("%d ", now);
    now = off + ((now * p) % mod);
  }
  return 0;
}