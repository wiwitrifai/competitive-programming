#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0, ma = 0;
  for(int i = 0; i<n; i++) {
    int a;
    scanf("%d", &a);
    sum += a;
    ma = max(ma, a);
  }
  if(n == 1) {
    puts("2");
  }
  else if(ma + ma >= sum)
    puts("1");
  else
    puts("0");
  return 0;
}