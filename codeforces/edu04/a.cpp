#include <bits/stdc++.h>

using namespace std;

char s[105];
int n, p, q;

int main() {
  scanf("%d%d%d", &n, &p, &q);
  scanf("%s", s);
  int x = n/p;
  for(int i = 0; i<=x; i++) {
    if((n-i*p) % q == 0) {
      int k = 0;
      int y = (n-i*p)/q;
      printf("%d\n", y+i);
      for(int j = 0; j<i; j++) {
        for(int z = 0; z<p; z++)
          printf("%c", s[k++]);
        printf("\n");
      }
      for(int j = 0; j<y; j++) {
        for(int z = 0; z<q; z++)
          printf("%c", s[k++]);
        printf("\n");
      }
      return 0;
    }
  }
  puts("-1");
  return 0;
}