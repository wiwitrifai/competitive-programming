#include <bits/stdc++.h>

using namespace std;

int xx[] = {0, 0, 1, 1,}, yy[] = {0, 1, 0, 1};

int main() {
  int n, a, b, c;
  scanf("%d", &n);
  a = 1;
  b = 0;
  c = 0;
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    int aa, bb, cc;
    aa = bb = cc = n+1;
    aa = min(a,min(b, c)) + 1;
    if(xx[x]) {
      cc = min(a, b);
    }
    else
      cc = n+1;
    if(yy[x])
      bb = min(a, c);
    else
      bb = n+1;
    a = aa;
    b = bb;
    c = cc;
  }
  printf("%d\n", min(min(a, b), c));
  
  return 0;
}