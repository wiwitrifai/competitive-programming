#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int a[10005];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  int k = 0;
  for(int i = 1; i < n; i++) {
    k += (gcd(a[i], a[i-1]) > 1);
  }
  printf("%d\n", k);  
  printf("%d", a[0]);
  for(int i = 1; i < n; i++) {
    if(gcd(a[i], a[i-1]) > 1)
      printf(" 1");
    printf(" %d", a[i]);
  }
  printf("\n");
  return 0;
}