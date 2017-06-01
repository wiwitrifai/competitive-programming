#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[3], b[3];
  for(int i = 0; i<3; i++)
    scanf("%d", a+i);
  for(int j = 0; j<3; j++)
    scanf("%d", b+i);
  int d, c;
  d = c = 0;
  for(int i = 0; i<3; i++) {
    c += (a[i] > b[i]);
    d += (a[i] < b[i]);
  }
  printf("%d %d\n", c, d);
  return 0;
}