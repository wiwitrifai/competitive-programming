#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int ans = 1 + (3*n+3)*n;
    for(int i = 1; i<=n; i++) {
      for(int j = 1; j<=n; j++) {
        int a = i*j, b = (n+1-i) *(n+1-j);
        int c = gcd(a, b);
        a /= c; b /= c;
        c = a+b;
        if(((n+1) % c) == 0)
          ans--;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}