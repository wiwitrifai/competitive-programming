#include <bits/stdc++.h>

using namespace std;

int a[1005];
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
      scanf("%d", a+i);
    }
    sort(a, a+n);
    int x, y;
    x = y = -1;
    for(int i = n-1; i>0; i--) {
      if(a[i] == a[i-1]) {
        if(x == -1) {
          x = a[i];
          i--;
        }
        else {
          y = a[i];
          break;
        }
      }
    }
    if(x > 0 && y > 0)
      printf("%d\n", x*y);
    else
      puts("-1");
  }

  return 0;
}