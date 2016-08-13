#include <bits/stdc++.h>

using namespace std;

int n, b, p;

int main() {
  cin >> n >> b >> p;
  int tmp;
  int ans1 = 0, ans2 = n * p;
  while(n > 1) {
    int now = 1;
    while(now*2 <= n)
      now <<= 1;
    ans1 += now/2;
    n -= now/2;
  }
  ans1 *= (2*b+1);
  printf("%d %d\n", ans1, ans2);
  
  return 0;
}