#include <bits/stdc++.h>

using namespace std;

int calc(int x) {
  int r = 0;
  while (x) {
    r += x % 10;
    x /= 10;
  }
  return r;
}

int main() {  
  int n;
  scanf("%d", &n);
  int ans = 1e9;
  for (int a = 1; n-a >= 1; ++a) {
    int b = n-a;
    ans = min(calc(a) + calc(b), ans);
  }
  printf("%d\n", ans);
  return 0;
}