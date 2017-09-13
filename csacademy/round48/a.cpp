#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);  
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a += x;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    b += x;
  }
  if (a == b)
    puts("0");
  else if (a > b)
    puts("1");
  else
    puts("2");
  return 0;
}