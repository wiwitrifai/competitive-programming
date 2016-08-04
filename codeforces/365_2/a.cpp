#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int m, c;
  m = c = 0;
  for(int i= 0; i<n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    m += (a > b);
    c += (a < b);
  } 
  if(m > c)
    puts("Mishka");
  else if (m < c)
    puts("Chris");
  else
    puts("Friendship is magic!^^");

  return 0;
}