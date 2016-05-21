#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc<=t; tc++) {
    int k, c, s;
    scanf("%d%d%d", &k, &c, &s);
    printf("Case #%d:", tc);
    if(s < (k+1)/2)
      puts(" IMPOSSIBLE");
    else {
      int mul = 1;
      while(--c) {
        mul *= k;
      }
      for(long long i = 0; i<k; i+=2) {
        printf(" %lld", i + i*mul + 1);
      }
      printf("\n");
    }
  }
  return 0;
}