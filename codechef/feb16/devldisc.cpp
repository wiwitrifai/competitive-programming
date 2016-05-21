#include <bits/stdc++.h>

using namespace std;

int tt, n;

int main() {
  scanf("%d", &tt);
  while(tt--) {
    scanf("%d", &n);
    if(n < 7)
      printf("-1\n");
    else {
      printf("%d\n", n);
      if(n & 1) {
        printf("%d %d\n", 1, 2);
        printf("%d %d\n", 2, n);
        for(int i = 2; i<n; i++)
          printf("%d %d\n", i, i+1);
        printf("%d\n", n);
      }
      else {
        printf("%d %d\n", 1, 3);
        printf("%d %d\n", 3, n);
        for(int i = 3; i<n; i++)
          printf("%d %d\n", i, i+1);
        printf("%d %d\n", n-1, 2);
        printf("%d\n", n);
      }
    }
  }
  return 0;
}