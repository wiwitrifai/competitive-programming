#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a, b;
  a = 1;
  b = 2*n+1;
  int ma = min(2*n, m);
  while(a <= ma || b <= m) {
    if(b <= m)
      printf("%d ", b);
    if(a <= ma)
      printf("%d ", a);
    if(b+1 <= m)
      printf("%d ", b+1);
    if(a+1 <= ma)
      printf("%d ", a+1);
    a += 2;
    b += 2;
  }
  printf("\n");
  return 0;
}