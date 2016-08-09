#include <bits/stdc++.h>

using namespace std;

int grund[55];

int main() {
  int n;
  int now = 0;
  scanf("%d", &n);
  while(n--) {
    int a;
    scanf("%d", &a);
    now ^= (a-1) & 1;
    puts(now ? "1" : "2");
  }
  
  return 0;
}