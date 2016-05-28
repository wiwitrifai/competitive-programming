#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    long long e, o;
    scanf("%d%lld%lld", &n, &e, &o);
    if(o == 0) {
      for(int i = 0; i<n; i++)
        printf("2 ");
      printf("\n");
      continue;
    }
    bool found = false;
    long long a, tot = e + o;
    for(int i = 1; i<=n; i++) {
      a = n+1 - i;
      if(a * i == o) {
        found = true;
        break;
      }
    }
    if(!found) {
      puts("-1");
      continue;
    }
    a--;
    for(int i = 0; i<a; i++)
      printf("2 ");
    printf("1 ");
    int sisa = n - 1 - a;
    for(int i = 0; i<sisa; i++)
      printf("2 ");
    printf("\n");
  }

  return 0;
}